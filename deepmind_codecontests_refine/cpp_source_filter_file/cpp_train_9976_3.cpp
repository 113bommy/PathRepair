#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  int a=1;
  for (int i=2;i*i<=x;i++){
    int t=i*i;
    while (tmp <= x) {
      ans=max(a,t);
      t*=i;
    }
  }
  cout << a << endl;
}
