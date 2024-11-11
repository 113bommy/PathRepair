#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,x,a[110];
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int ans=0;
  for(int i=0;i<n;i++){
    if(x>=a[i]){
      x-=a[i];
      ans++;
    }
  }
  if (ans==n&& x>0) {
    ans--;
  }
  cout<<ans;

}
