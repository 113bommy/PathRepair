#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<a+b+c+d-max({a,b})-max({c,d})<<endl;
}
