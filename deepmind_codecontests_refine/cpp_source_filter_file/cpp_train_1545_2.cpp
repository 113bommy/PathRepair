#include <iostream>
#include <map>
using namespace std;
int N,M,mx;
string t,s[110];
map< string,int > mp;
int main(){
    cin >>N ;
    for (int i = 0; i < N;++i) cin >> s[i], mp[s[i]]++;
    cin >> M;
    while(--M) cin >> t;mp[t]--;
    for (int i = 0;i < N;++i) mx = max(mx,mp(s[i]));
    cout << mx ;
}
