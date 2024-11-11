#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

vector<int> v;

ll dfs(ll i, ll N, ll K, ll *a, ll m) {
    if (i == N) {
        if (v.size() < K)
            return 999999999999;
        
        return 0;
    }

    ll ans;
    if (a[i] <= m) {
        v.push_back(i);
        ans = m+1-a[i]+dfs(i+1, N, K, a, m+1);
        v.pop_back();
        ans = min(ans, dfs(i+1, N, K, a, m));
        return ans;
    }
    else {
        v.push_back(i);
        ans = dfs(i+1, N, K, a, a[i]);
        v.pop_back(i);
        return ans;
    }
}

int main() {
    ll N, K;   cin >> N >> K;
    ll *a = new ll[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    
    cout << dfs(0, N, K, a, 0) << endl;

    return 0;
}