#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  long long n;
  cin >> a;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '^') {
      n = i;
      break;
    }
  }
  long long left = 0, right = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] - 48 >= 1 && a[i] - 48 <= 9) left += (a[i] - 48) * (n - i);
  }
  for (int i = n + 1; i < a.length(); i++) {
    if (a[i] - 48 >= 1 && a[i] - 48 <= 9) {
      right += (a[i] - 48) * (i - n);
    }
  }
  if (left == right)
    cout << "balance";
  else
    cout << ((left > right) ? "Left" : "Right");
  return 0;
}
