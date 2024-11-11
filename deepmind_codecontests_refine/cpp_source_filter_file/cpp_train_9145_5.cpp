#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,t;
  cin >>k >>t;
  int a[k];
  for(int i=0;i<t;i++)cin >>a[i];
  sort(a,a+t);
  int ans=a[t-1];
  cout <<max(K-2*ans-1,0)<<endl;
}
