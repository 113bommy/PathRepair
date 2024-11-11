#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  string n;
  cin >> k >> n;
  long long d = 0;
  for (int i = 0; i < n.size(); i++) d += n[i] - '0';
  if (k <= d) {
    cout << 0;
    exit(0);
  } else {
    int diff = k - d;
    sort(n.begin(), n.end());
    int p = 0;
    int i = 0;
    while (diff >= 0 && i < n.size()) {
      diff -= 9 - (n[i++] - '0');
      ++p;
    }
    cout << p << endl;
  }
}
