#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  for (int i = (0); i < (n); i++) {
    int t;
    cin >> t;
    a.push_back(t);
  }
  vector<int> b;
  for (int i = (0); i < (n); i++) {
    int t;
    cin >> t;
    b.push_back(t);
  }
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  long long r = 0;
  long long r1 = 0;
  int i = 0;
  int j = 0;
  int nn = 2 * n;
  int s = 1;
  while (nn--) {
    if (s == 1) {
      if (i < n && j < n) {
        if (a[i] > b[j]) {
          r += a[i];
          i++;
        } else {
          j++;
        }
      } else if (j < n) {
        j++;
      } else if (i < n) {
        r += a[i];
        i++;
      }
    } else {
      if (i < n && j < n) {
        if (b[j] > a[i]) {
          r1 += b[j];
          j++;
        } else {
          i++;
        }
      } else if (j < n) {
        r1 += b[j];
        j++;
      } else if (i < n) {
        i++;
      }
    }
    s ^= 1;
  }
  cout << r - r1 << endl;
  return 0;
}
