#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

template<unsigned MOD_> struct ModInt {
    static const unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const { return pow(MOD-2); }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    ModInt extgcd() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const LL MOD = 1000000007;
//const LL MOD = 998244353;
typedef ModInt<MOD> Mint;
const int MAX = 1000011;
Mint inv[MAX], fact[MAX], fact_inv[MAX];

void init() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++) fact[i] = fact[i-1] * i;
    fact_inv[MAX-1] = fact[MAX-1].inv();
    for (int i=MAX-2; i>=0; i--) fact_inv[i] = fact_inv[i+1] * (i+1);
    inv[0] = 0;
    for (int i=1; i<MAX; i++) inv[i] = fact_inv[i] * fact[i-1];
}

Mint nCk(int n, int k) {
    return fact[n] * fact_inv[k] * fact_inv[n-k];
}

Mint f(int a, int A, int b, int B) {
    return Mint(b).pow(A)*a + Mint(a).pow(B)*b - a*b;
}

Mint mem[111][111];
Mint g(int a, int A, int b, int B, int c, int C) {
    Mint ans = 0;
    memset(mem, 0, sizeof mem);

    for (int x=A-1; x>0; x--) for (int y=B-1; y>0; y--) {
	Mint p = Mint(c).pow((A-x)*(B-y)) - 1;
	Mint way = nCk(A, x) * nCk(B, y);
	for (int x1=x; x1<A; x1++) for (int y1=y; y1<B; y1++) {
	    mem[x][y] -= mem[x1][y1] * nCk(x1, x) * nCk(y1, y);
	}
	mem[x][y] += p * way;
	Mint tmp = (Mint(b).pow(x) + Mint(a).pow(y) - 1).pow(C);
	tmp -= Mint(b).pow(x).pow(C);
	tmp -= Mint(a).pow(y).pow(C);
	tmp += 1;
	ans += mem[x][y] * tmp * a * b * c;
    }
    return ans;
}

void MAIN() {
    init();
    int a, b, c, A, B, C;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &A, &B, &C);  
    Mint ans;
    if (A % a == 0 && B % b == 0 && C % c == 0) {
	A /= a; B /= b; C /= c;
	ans += f(a, A, b, B).pow(C) * c;
	ans += f(b, B, c, C).pow(A) * a;
	ans += f(c, C, a, A).pow(B) * b;

	ans -= Mint(c).pow(A*B)*a*b;
	ans -= Mint(a).pow(B*C)*b*c;
	ans -= Mint(b).pow(C*A)*c*a;

	ans += a*b*c;

	ans += g(a, A, b, B, c, C);
    }
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

