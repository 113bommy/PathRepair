#include <bits/stdc++.h>
using namespace std;
void Oli() {
  long long int a, k;
  cin >> a >> k;
  string c;
  cin >> c;
  for (long long int i = 0; i < c.size(); i += 0) {
    if (i == c.size() - 1) break;
    long long int max = -1;
    for (long long int j = k + i; j >= i + 1; j--) {
      if (j >= c.size()) {
        j = c.size() - 1;
      }
      if (c[j] == '.') {
        max = j;
        break;
      }
    }
    if (max == -1) {
      cout << "NO";
      return;
    } else {
      i += max;
    }
  }
  cout << "YES" << endl;
}
int main() {
  int times = 1;
  while (times--) Oli();
}
