#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    int n,m;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> s;
        mp[s]--;
    }
    int ans=0;
    for(auto u:mp)ans=max(ans,u.second);
    cout << ans << endl;
}