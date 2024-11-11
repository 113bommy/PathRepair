#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int m=0,c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T') c++;
        else c=0;
        m=max(m,c);
    }
    cout<<m<<endl
    return 0;
}