#include <bits/stdc++.h>
#define r(i,n) for(i=0;i<n;i++)
using namespace std;
int main(){
  int n,i,j,q;
  while(cin>>n,n){
    int m=0,tt;
    string p[n],s[n];
    r(i,n){cin>>p[i];}
    r(i,n){tt=p[i].size();r(j,tt){
      if(!j)s[i]+=p[i][j];
      else{if(p[i][j-1]=='a'||p[i][j-1]=='i'||p[i][j-1]=='u'||p[i][j-1]=='e'||p[i][j-1]=='o')s[i]+=p[i][j];}
    }}
    r(i,n){tt=s[i].size();m=max(m,tt);}
    string t[n];
    r(i,m){
      int p=0;
      r(j,n)if(i<s[j].size())t[j]+=s[j][i];
    r(j,n)for(int k=j+1;k<n;k++)if(t[k]==t[j])p++;
      if(!p)goto L;
    }
    cout<<-1<<endl;
    if(0){L:;cout<<i+1<<endl;}
  }
}