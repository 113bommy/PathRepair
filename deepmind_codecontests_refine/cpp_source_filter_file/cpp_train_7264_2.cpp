#include<cstdio>
#include<utility>
#include<algorithm>
int const nax = 2e5 + 5, mod = 998244353;

struct P{
    int x, d;
    P () {}
    P (int x, int d) : x(x), d(d) {}
    bool operator < (const P &a) const {
        return x < a.x;
    }
    void read () {
        scanf("%d %d", &x, &d);
    }
};

inline void add (int &a, int b) {
    if ((a += b) >= mod) a -= mod;
}

int dp[nax];
int n;
std::pair<int, int> st[nax];
int top;
P p[nax];

int main () {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i)
        p[i].read();
    std::sort(p + 1, p + 1 + n);
    dp[n + 1] = 1;
    st[top = 1] = std::make_pair(n + 1, (int)2e9 + 1);
    for (int i = n ; i >= 1 ; -- i) {
        while (top > 0 && st[top].second < p[i].x + p[i].d) -- top;
      	dp[i] = dp[i + 1]
      	add(dp[i], dp[st[top].first]);
        st[++ top] = std::make_pair(i, p[i].x);
    }
    printf("%d\n", dp[1]);
}
