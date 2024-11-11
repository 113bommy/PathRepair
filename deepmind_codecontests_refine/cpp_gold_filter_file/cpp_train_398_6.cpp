#include <bits/stdc++.h>
using namespace std;
string s,g;
char hs(char c){
    if(c=='b') return 'd';
    if(c=='d') return 'b';
    if(c=='p') return 'q';
    return 'p';
}
int i,j,k,l,m,n,b;
int main(){
    cin>>s;
    for(i=0;i<s.size();i++){
        g+=hs(s[s.size()-i-1]);
    }
    if(s==g) cout<<"Yes";
    else cout<<"No";
    return 0;
}