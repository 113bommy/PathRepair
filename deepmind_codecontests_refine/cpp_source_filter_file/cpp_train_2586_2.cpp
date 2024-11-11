#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int num=0;
  int bottun=1;
  cin>>n;
  vector<int>a(n);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  while(bottun!=2){
    bottun=a[bottun];
    num++;
    if(num>N) break;
  }
  if(num<N) cout<<num<<endl;
  else cout<<-1<<endl;
}
    