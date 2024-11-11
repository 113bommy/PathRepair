#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin>>s;
    sort(s.begin(),s.end());
    if (s[0]==s[1]&&s[1]!=s[2]&&s[2]==s[3]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
