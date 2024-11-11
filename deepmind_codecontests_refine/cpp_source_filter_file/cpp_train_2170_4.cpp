#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a,at(i);
    if(a.at(i)%2==0)x*=2;
  }
  x=pow(3,n)-x;
  cout<<x<<endl;
}