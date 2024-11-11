#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int b1,b2;
  cin >> b1;
  int sum = b1;
  for(int i = 0;i < n - 2;i++) {
    cin >> b2;
    sum += min(b1,b2);
    b1 = b2;
  }
  sum += b1;
  cout << sum << endl;
}