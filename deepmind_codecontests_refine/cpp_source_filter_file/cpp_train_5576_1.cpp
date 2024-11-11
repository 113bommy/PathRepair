#include <bits/stdc++.h>
using namespace std;
int n, t;
char c;
bool ok = false;
vector<int> calc, v;
int l = 0, remind = 0, up = 0, stay = 0;
void gg() {
  for (int i = 0; i < v.size(); ++i) cout << v[i];
  if (remind == 1) return;
  cout << '.';
  for (int i = 0; i < calc.size(); ++i) {
    if (calc[i] == 0) break;
    cout << calc[i];
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    if (ok) {
      calc.push_back(c - 48);
      continue;
    }
    if (c == '.') {
      ok = true;
      continue;
    }
    v.push_back(c - 48);
  }
  for (int i = 0; i < calc.size(); ++i) {
    if (calc[i] > 4) {
      up = i;
      break;
    }
  }
  for (int i = up; i >= 0; --i) {
    if (t == 0) break;
    if (calc[i] > 4 && i > 0) {
      ++calc[i - 1], calc[i] = 0, --t;
      continue;
    }
    if (calc[i] > 4 && i == 0) ++v[v.size() - 1], remind = 1, --t, calc[i] = 0;
    if (calc[i] < 5) break;
  }
  for (int i = v.size() - 1; i > 0; --i) {
    if (v[i] < 10) break;
    ++v[i - 1], v[i] = 0;
  }
  return gg(), 0;
}
