#include <bits/stdc++.h>
using namespace std;
inline istream& skip_endl(istream& is) {
  return is.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i <= n - 1; i++) {
    cin >> v[i];
  }
  int p1 = -1, p2 = -1;
  for (int i = 0; i <= n - 1; i++) {
    if (v[i] == 1) {
      p1 = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == 1) {
      p2 = i;
      break;
    }
  }
  if (p1 == p2) {
    if (p1 == -1) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  } else {
    int zero_block = 0;
    int ways = 1;
    for (int i = p1 + 1; i <= p2 - 1; i++) {
      if (v[i] == 0) {
        zero_block++;
      } else {
        ways *= (zero_block + 1);
        zero_block = 0;
      }
    }
    cout << ways * (zero_block + 1) << "\n";
  }
  return 0;
}
