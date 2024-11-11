#include <bits/stdc++.h>
int main() {
  using namespace std;
  long int d, count = 0;
  int n, x;
  cin >> d;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    count += d - x;
  }
  cout << count;
}
