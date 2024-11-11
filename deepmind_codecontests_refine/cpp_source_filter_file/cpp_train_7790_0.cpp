#include <cstdio>
#include <iostream>
#include <bitset>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

const int N = 4010;
const int mod = 998244353;

bitset <N> x, y, G, a[10];
int n;

bitset <N> gcd(bitset <N> A, bitset <N> B)
{
    int i = N - 1, j = N - 1;
    while(1)
    {
        for(; ~i && !A[i]; --i);
        for(; ~j && !B[j]; --j);
        if (i == -1) return B;
        if (j == -1) return A;
        if (i > j) A ^= (B << (i - j));
            else B ^= (A << (j - i));
    }
}

int div(bitset <N> A, bitset <N> B)
{
    int i = N - 1, j = N - 1, ans = 0;
    for(; ~j && ~B[j]; --j);
    for(; i >= j; --i)
    {
        ans = (ans * 2 + (A[i] ? 1 : 0)) % mod;
        if (A[i] != y[i]) y[i] ^= B << (i - j);
    }
    for(int i = N - 1; ~i; --i) if (A[i] < y[i])
    {
        ans = (ans - 1 + mod) % mod;
        break;
    }
    else if (A[i] > y[i]) break;
    return ans;
}

int main()
{
    cin >> n >> x;
    FOR(i, 1, n) cin >> a[i];
    G = a[1];
    FOR(i, 2, n) G = gcd(G, a[i]);
    printf("%d\n", (div(x, G) + 1) % mod);
    return 0;
}
;
