#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x,a[101],ans=0;
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(int i=0;i<n-1;i++){
    if(a[i]>x){
      break;
    }
    x-=a[i];
    ans++;
  }
  puts(x==array[n-1]?ans+1:ans);
}
