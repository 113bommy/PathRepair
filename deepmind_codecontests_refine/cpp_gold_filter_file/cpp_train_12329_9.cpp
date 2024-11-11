#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    if (x == 'B') {
      sum += pow(2, i);
    }
  }
  cout << sum;
  return 0;
}
