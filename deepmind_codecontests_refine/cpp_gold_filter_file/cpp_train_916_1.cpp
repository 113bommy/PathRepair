#include<bits/stdc++.h>
using namespace std;
long s,r,x;
int main(int n) {
  cin>>n;
  map<long,int> c;
  c[0]=1;
  while(n--)cin>>x,r+=c[s+=x]++;
  cout<<r<<endl;
}
