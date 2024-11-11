include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main(){

  long long cnt=0;
  int n,x,flg;
  char p;
  short a=0;

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> p >> x;
    if(p=='(')cnt+=x;
    else cnt-=x;

    if(cnt<0)a=1;
  }
  if(cnt!=0 || a==1)cout << "NO" << endl;
  else cout << "YES" << endl;
   
}