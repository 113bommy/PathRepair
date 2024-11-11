#include <bits/stdc++.h>
using namespace std;
long long pa(int n, int p) {
  if (p == 0) {
    return 1;
  }
  return n * pa(n, p - 1);
}
int main() {
  long long first, second, n, b, x;
  cin >> n >> b;
  first = 0;
  for (int i = n - 1; i >= 0; --i) {
    cin >> x;
    first += x * pa(b, i);
  }
  cin >> n >> b;
  second = 0;
  for (int i = n - 1; i >= 0; --i) {
    cin >> x;
    second += x * pa(b, i);
  }
  if (first > second) {
    cout << ">" << endl;
  } else if (second > first) {
    cout << "<" << endl;
  } else {
    cout << "=" << endl;
  }
  return 0;
}
