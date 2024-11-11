#include <bits/stdc++.h>
using namespace std;
long n;
int main() {
  cin >> n;
  vector<long long> b(n + 1);
  for (long i = 1; i <= n; ++i) cin >> b[i];
  if (n == 2 || n == 3) {
    cout << 1;
  } else {
    vector<long long> c = b;
    sort(b.begin(), b.end());
    long long diff1 = b[2] - b[1];
    bool removed = false;
    long removeIndex1 = 1;
    for (int i = 1; i < b.size(); ++i) {
      if (!removed && b[i] != b[1] + (i - 1) * diff1) {
        removeIndex1 = i;
        removed = true;
      } else if (removed && b[i] != b[1] + (i - 2) * diff1) {
        removeIndex1 = -1;
        break;
      }
    }
    long long diff2 = b[3] - b[1];
    long removeIndex2 = 2;
    for (int i = 3; i < b.size(); ++i) {
      if (b[i] != b[1] + (i - 2) * diff2) {
        removeIndex2 = -1;
        break;
      }
    }
    long long diff3 = b[3] - b[2];
    long removeIndex3 = 1;
    for (int i = 2; i < b.size(); ++i) {
      if (b[i] != b[2] + (i - 2) * diff3) {
        removeIndex3 = -1;
        break;
      }
    }
    if (max(max(removeIndex1, removeIndex2), removeIndex3) == -1) {
      cout << -1;
    } else {
      for (int i = 1; i < c.size(); ++i) {
        if (c[i] == b[max(max(removeIndex1, removeIndex2), removeIndex3)]) {
          cout << i;
          break;
        }
      }
    }
  }
  return 0;
}
