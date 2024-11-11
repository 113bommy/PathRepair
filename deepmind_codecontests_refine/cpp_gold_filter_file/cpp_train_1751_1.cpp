#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MN = 200010;

int N;
int A[MN], D[MN];
ll dp1[MN], dp2[MN];
vector<pii> seg;

void solve(ll *dp) {
    for(int i = 1; i < N; i++) {
        ll p = 4;
        while(p * A[i - 1] <= A[i]) {
            D[i]++;
            p *= 4;
        }
    }

    seg.clear();

    dp[N - 1] = 0;
    seg.push_back(pii(N - 1, N - 1));
    for(int i = N - 2; i >= 0; i--) {
        dp[i] = dp[i + 1];

        if(A[i + 1] < A[i]) {
            ll p = 1;
            int cnt = 0;
            while(p * A[i + 1] < A[i]) {
                cnt++;
                p *= 4;
            }

            pii tmp = pii(i, i);
            while(seg.size()) {
                if(cnt < D[ seg.back().first ]) {
                    D[ seg.back().first ] -= cnt;
                    break;
                }
                dp[i] += (cnt - D[ seg.back().first ]) * (seg.back().second - seg.back().first + 1);
                cnt -= D[ seg.back().first ];
                D[ seg.back().first ] = 0;
                tmp.second = seg.back().second;
                seg.pop_back();
            }
            seg.push_back(tmp);
        }
        else {
            if(D[ seg.back().first ]) seg.push_back(pii(i, i));
            else seg.back().first = i;
        }
    }
}

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    solve(dp1);
    reverse(A, A + N);
    solve(dp2);

    ll ans = 1e18;
    for(int i = 0; i <= N; i++) {
        ans = min(ans, 2 * dp1[i] + 2 * dp2[N - i] + i);
    }
    printf("%lld", ans);
}
