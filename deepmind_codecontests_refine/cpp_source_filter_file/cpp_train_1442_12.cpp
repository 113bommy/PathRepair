#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  cin>>r>>g>>b;
  cout<<((10*g+b)%4 == 0 ? "YES:"NO)<<endl;
}