#include <bits/stdc++.h>
long long const mod = 1e14 + 7;
long long const INFll = 1e18;
int const INF = 2e9;
double const eps = 1e-7;
using namespace std;
int main() {
  if (0) {
    if (1) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    } else {
      freopen("evacuation.in", "r", stdin);
      freopen("evacuation.out", "w", stdout);
    }
  }
  string name, st;
  cin >> name >> st;
  int it = 0, is = 0;
  for (it = 0; it < st.size(); it++) {
    if (is < name.size() && st[it] == name[is]) {
      is++;
    }
    if (is == name.size()) {
      break;
    }
  }
  is--;
  for (int i = st.size() - 1; i >= 0; i--) {
    if (is >= 0 && st[i] == name[is]) {
      is--;
    }
    if (is < 0) {
      cout << max(0, i - it);
      return 0;
    }
  }
  cout << 0;
}
