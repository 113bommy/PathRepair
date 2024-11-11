#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N;
    ll M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    sort(A.begin(),A.end());
    vector<ll> sum(N+1);
    for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];

    auto calc = [&](int x){
        ll tot = 0, num = 0;
        for (int i=0;i<N;i++){
            int j = lower_bound(A.begin(),A.end(),x-A[i]) - A.begin();
            num += N - j;
            tot += sum[N] - sum[j];
            tot += A[i]*(ll)(N-j);
        }
        return make_pair(tot,num);
    };

    int lower = -1;
    int upper = 200005;
    while (upper - lower >1){
        int mid = (upper + lower)/2;
        if (calc(mid).second >= M) lower = mid;
        else upper = mid;
    }
    auto p = calc(lower);
    ll ans = p.first;
    ans -= (p.second - M)*lower;
    cout << ans << endl;

    return 0;
}