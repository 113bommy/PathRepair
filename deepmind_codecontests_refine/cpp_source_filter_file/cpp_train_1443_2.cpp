#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    int arr[n];
    unordered_map<int, int> m, vis;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        m[arr[i]] += 1;
    }
    ll ans = 1;
    for(auto j:m){
        if(vis[j.first]) continue;
        if(j.second > 2) ans *= 0;
        if(j.first == 0 && j.second > 1) ans*=0;
        if(j.first != 0){ans *= 2; ans %= 1000000007}
        vis[j.first] = 1;
    }
    cout << ans << endl;
}