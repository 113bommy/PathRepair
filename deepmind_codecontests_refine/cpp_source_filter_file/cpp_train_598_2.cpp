#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long a[n];
  for (int i=0;i<n;i++)
    cin>>a[i];
  long long money=1000;
  for (int i=0;i<n-1;i++){
  	long long stocks=money/a[i];
    money+=stocks*max(a[i+1]-a[i],0);
  }
  cout<<money;
}
