#include <bits/stdc++.h>
using namespace std;
long long int n, c, a, b, s;
vector<long long int> p(50);
vector<long long int> t(50);
int main() {
  cin >> n >> c;
  for (long long int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (long long int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  a = s = 0;
  for (long long int i = 0; i < n; ++i) {
    s += t[i];
    a += max(0LL, p[i] - c * s);
  }
  b = s = 0;
  for (long long int i = 0; i < n; ++i) {
    s += t[n - i];
    b += max(0LL, p[n - i] - c * s);
  }
  if (a > b) {
    cout << "Limak" << endl;
  } else if (a == b) {
    cout << "Tie" << endl;
  } else {
    cout << "Radewoosh" << endl;
  }
  return 0;
}
