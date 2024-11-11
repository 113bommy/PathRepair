#include <bits/stdc++.h>
using namespace std;

long long k;
int n,now=1,a[223456][60];
int d(int now,int k){
  a[now][k]||a[now][k]=d(d(now,k-1),k-1);
  return a[now][k];
}

int main(){
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i][0];
  for(int i=0;i<60;i++)if((k>>i)&1)now=d(now,i);
  cout<<now<<endl;
}
