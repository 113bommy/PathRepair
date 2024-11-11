#include <bits/stdc++.h>
using namespace std;

int main() {
int n,m; cin>>n;
  m=(n/100)*111;
  if(n<=m)cout<<m<endl;
  else cout<<m+=111<<endl;
}
