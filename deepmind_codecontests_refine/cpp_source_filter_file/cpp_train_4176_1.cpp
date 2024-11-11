#include <bits/stdc++.h>
using namespace std;
bool resh[1000000];
vector<int> pr;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m, k;
  for (int i = 2; i < 100000; i++) {
    if (!resh[i]) {
      pr.push_back(i);
      for (int j = i * 2; j < 100000; j += i) {
        resh[j] = 1;
      }
    }
  }
  cin >> n >> m >> k;
  if (2 * n * m % k != 0) {
    cout << "NO";
    return 0;
  }
  long long dop = 2;
  if (k % 2 == 0) {
    k /= 2;
    dop = 1;
  }
  long long a = n, b = m;
  for (int i = 0; i < pr.size(); i++) {
    while (k % pr[i] == 0) {
      if (a % pr[i] == 0) {
        a /= pr[i];
      } else {
        b /= pr[i];
      }
      k /= pr[i];
    }
  }
  if (a < b) {
    a *= dop;
  } else {
    b *= dop;
  }
  cout << "YES\n";
  cout << "0 0\n";
  cout << a << " 0\n";
  cout << "0 " << b;
  return 0;
}
