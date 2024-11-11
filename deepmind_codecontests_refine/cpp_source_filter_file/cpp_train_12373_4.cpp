#include <bits/stdc++.h>
#define rep(i,b) for(ll i=0;i<b;i++)
using namespace std;
string s[50];
int n,m;
signed main() {
    cin>>n;
    rep(i,n)cin>>s[i];
    rep(j,26) {
        m = 100;
        rep(i, n)m = min(m, (int) count(begin(s[i]), end(s[i]),(char)j+97));
        rep(i, m) cout <<(char)(j+97);
    }
    cout << endl;
}