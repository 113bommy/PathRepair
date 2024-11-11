#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> v;
  for (long long i = 0; i < n; ++i) {
    long long val;
    cin >> val;
    v.push_back(val);
  }
  long long i = 1;
  long long mn = numeric_limits<long long>::max();
  long long mx = numeric_limits<long long>::min();
  bool dw = false;
  long long mindx = 0, maxidx = 0;
  long long cw = 0;
  while (i < v.size()) {
    long long dif = v[i] - v[i - 1];
    if (dif > 0) {
      mn = v[i - 1];
      if (dw && v[mindx] > v[i]) {
        cout << "no" << endl;
        return 0;
      }
      dw = false;
      ++i;
    } else {
      if (!dw) {
        dw = true;
        if (cw >= 1) {
          cout << "no" << endl;
          return 0;
        }
        mindx = i - 1;
        ++cw;
      }
      if (v[i] > mn) {
        cout << "no" << endl;
        return 0;
      }
      maxidx = i;
      ++i;
    }
  }
  cout << "yes" << endl;
  cout << mindx + 1 << " " << maxidx + 1 << endl;
  return 0;
}
