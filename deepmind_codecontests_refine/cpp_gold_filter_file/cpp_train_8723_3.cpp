#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

int main(void){
  int n;
  cin>>n;
  vector<ll>a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i&1)b[0]-=a[i];
    else b[0]+=a[i];
}
  b[0]/=2;
  for(int i=1;i<n;i++){
    b[i]=a[i-1]-b[i-1];
  }
  for(int i=0;i<n;i++){
    cout<<2*b[i]<<" ";
  }
  cout<<endl;
}
