#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=1;
  cin >>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >>a[i];
    if(a[i]%2==0)ans*=2;
  }
  cout << pow(3,n)-ans<<endl;
}
