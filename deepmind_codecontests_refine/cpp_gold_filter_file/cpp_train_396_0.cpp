#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[1<<26];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    string s;
    cin>>s;
    int n = s.size();
    int INF = 1e9;
    for(int i=0;i<(1<<26);i++) cnt[i] = INF;
    cnt[0] = 0;
    int now = 0;
    int ans;
    for(int i=0;i<n;i++){
        now ^= (1<<(s[i]-'a'));
        int ret = 1e9;
        for(int j=0;j<26;j++){
            ret = min(ret,cnt[now^(1<<j)]+1);
        }
        cnt[now] = min(cnt[now],ret);
        ans = cnt[now];
        //cerr << i << " " << ans << endl;
    }
    ans = max(ans,1);
    cout << ans << endl;
}