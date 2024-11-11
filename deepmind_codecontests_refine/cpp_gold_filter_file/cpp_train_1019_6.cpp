#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,e,f;
  string b;

  cin>>a>>b;
  vector<int>c(a+1),d(a+1);
  c[0]=0;
  d[0]=0;
  f=a;
  for(int i=0;i<a;i++){
      if(b[i]=='#'){
        c[i+1]=c[i]+1;
        d[i+1]=d[i];
      }
      else{
        c[i+1]=c[i];
        d[i+1]=d[i]+1;
      }
    }
 for(int i=0;i<a;i++){
f=min(f,c[i]+d[a]-d[i+1]);
 }

cout<<f<<endl;
}
