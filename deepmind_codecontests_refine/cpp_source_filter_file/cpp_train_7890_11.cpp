#include<bits/stdc++.h>
using namespace std;
int a,b;
string s;
char c;
int main(){
    cin>>a>>s>>b;
    c=s[b-1];
    for(int i=0;i<n;i++)if(s[i]==c)cout<<c;
    else cout<<'*';
    cout<<endl;
    return 0;
}