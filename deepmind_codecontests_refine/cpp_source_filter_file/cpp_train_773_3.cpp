#include <bits/stdc++.h>
using namespace std;
int p, n;
bool build(string& in, int i) {
  bool gg = 0;
  for (char v = in[i] + 1; v <= p; ++v) {
    if ((i - 1 < 0 || in[i - 1] != v) && (i - 2 < 0 || in[i - 2] != v)) {
      gg = true;
      in[i] = v;
      break;
    }
  }
  if (gg) {
    bool can = true;
    for (int j = i + 1; j < n; ++j) {
      can = false;
      for (char v = 'a'; v <= p; ++v) {
        if ((i - 1 < 0 || in[i - 1] != v) && (i - 2 < 0 || in[i - 2] != v)) {
          can = true;
          in[j] = v;
          break;
        }
      }
      if (!can) {
        break;
      }
      if (j + 1 == n) {
        cout << in << endl;
        return 0;
      }
    }
    if (can) {
      cout << in << endl;
      return 0;
    }
  }
  return 1;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> p;
  p += 'a' - 1;
  string in;
  cin >> in;
  for (int i = n; i-- > 0;) {
    if (!build(in, i)) {
      return 0;
    }
  }
  cout << "NO" << endl;
}
