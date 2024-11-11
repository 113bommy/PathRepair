#include <bits/stdc++.h>
using namespace std;
bool cmp(string &a, string &b) { return a.size() < b.size(); }
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  unsigned long long int number1 = 0;
  unsigned long long int number2 = 0;
  if (n > 36) {
    cout << -1 << "\n";
    return 0;
  } else if (n % 2 == 0) {
    int limit = n / 2;
    while (limit--) {
      cout << 8;
    }
    cout << "\n";
  } else {
    int limit = n - 1;
    limit /= 2;
    while (limit--) {
      cout << 8;
    }
    cout << 0;
  }
  return 0;
}
