#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int k;
  cin >> a >> k;
  int maxVal = 0;
  int idx = 0;
  int pos = 0;
  int len = a.size();
  while (1) {
    bool chk = false;
    idx = 0;
    maxVal = a[pos] - '0';
    int jump = k;
    for (int i = pos + 1; i <= pos + k && i < len; i++) {
      if (maxVal < a[i] - '0') {
        chk = true;
        maxVal = a[i] - '0';
        idx = i;
      }
    }
    if (chk) {
      for (int j = idx; j > pos; j--) swap(a[j], a[j - 1]);
      k = k - (idx - (pos));
      pos++;
    } else if (!chk) {
      if (pos < len - 1)
        pos++;
      else
        break;
    }
  }
  cout << a << endl;
  return 0;
}
