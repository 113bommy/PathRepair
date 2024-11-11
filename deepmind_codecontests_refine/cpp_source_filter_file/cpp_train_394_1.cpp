#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;cin>>n>>x;
  int a[n];for(int i=0;i<n;i++){cin>>a[i];}
  int cnt=0;
  sort(a,a+n);
  for(int i=0;i<n-1;i++){if(a[i]>x)break;else{x-=a[i];cnt++;}}
  cout<<x-a[n-1]?cnt:cnt+1<<endl;
}