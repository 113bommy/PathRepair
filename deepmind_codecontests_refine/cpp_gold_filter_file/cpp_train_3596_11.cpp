#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int x;
  long long int count = 0;
  cin >> n >> x;
  long long int val[n];
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch >> val[i];
    if (ch == '+') {
      x = x + val[i];
    } else if (ch == '-') {
      if (x >= val[i]) {
        x = x - val[i];
      } else if (x < val[i]) {
        count = count + 1;
      }
    }
  }
  cout << x << " " << count << endl;
  return (0);
}
