#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
int main(){
  string s;
  while(cin>>s,s[0]!='#'){
    string t[9];
    int q=0,r=0,a,b,c,d;
    r(i,s.size()){
      if(s[i]=='/')r++,q=0;
      else if(s[i]=='b')t[r]+='b',q++;
      else r(j,s[i]-'0')t[r]+='.',q++;
    }
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    if(t[a][b]=='.')t[a][b]='b',t[c][d]='.';
    else t[a][b]='.',t[c][d]='b';
    r(i,r+1){r(j,q){
      if(t[i][j]=='b')cout<<'b';
      else{
        int p=0;
        for(;j<q;j++,p++)if(t[i][j+1]!='.')break;
        cout<<p+1;
      }
      }
      if(i!=r)cout<<'/';
    }
    cout<<endl;
  }