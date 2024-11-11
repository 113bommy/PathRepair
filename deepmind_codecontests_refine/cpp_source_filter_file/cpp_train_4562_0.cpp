#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(long long)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    reverse(A.begin(), A.end());
    vector<ll> sum(N+1), evensum(N+1);
    rep(i, N) {
        sum[i+1] = sum[i]+A[i];
        evensum[i+1] = evensum[i] + (i%2 == 0 ? A[i] : 0);
    }

    vector<ll> ths, vals;
    for (int k=0; k<(N-1)/2; ++k) {
        ll th = (A[k+1]+A[k*2+2])/2 + 1;
        ll val = sum[k+1] + evensum[N] - evensum[k*2+2];
        ths.push_back(th);
        vals.push_back(val);
    }
    reverse(ths.begin(), ths.end());
    reverse(vals.begin(), vals.end());
    rep(i, Q) {
        ll X;
        cin >> X;
        int index = upper_bound(ths.begin(), ths.end(), X) - ths.begin();
        if (index == 0) cout << sum[(N+1)/2] << endl;
        else cout << vals[index-1] << endl;
    }
    return 0;s
}
