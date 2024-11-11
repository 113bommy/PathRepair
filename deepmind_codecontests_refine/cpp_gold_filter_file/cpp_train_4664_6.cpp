#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, a, b, ans;
  cin >> A >> B;
  a=max((4-A),0);
  b=max((4-B),0);
  ans=100000*(a+b);
  if (A+B==2) {
    ans=ans+400000;
  }
  cout << ans << endl;
}
