#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  int N=count(S.begin(),S.end(),'N');
  int s=count(S.begin(),S.end(),'S');
  int E=count(S.begin(),S.end(),'E');
  int W=count(S.begin(),S.end(),'W');
  if((N*s==0&&N+s>0)||(E*W==0&&E+W>0))cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}