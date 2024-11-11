#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    string s;
    cin >> s;
    int ans = s.size();
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            ans--;
            i+=2;
        }
    }
    cout << ans << endl;
}