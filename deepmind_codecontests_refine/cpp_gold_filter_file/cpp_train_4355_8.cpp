#include<iostream>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int a[100009];
  for(int i=0;i<n;i++) cin>>a[i];
  cout<<(n-2)/(k-1)+1<<endl;
  return 0;
}
