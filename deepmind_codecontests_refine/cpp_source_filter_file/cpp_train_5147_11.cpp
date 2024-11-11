#include <bits/stdc++.h>
using namespace std;
int n, k;
bool played[1005][1005], matches[1005], ok = true;
vector<pair<int, int> > sol;
int main() {
  cin >> n >> k;
  if (k > n - 1) ok = false;
  if (ok) {
    cout << n * k << "\n";
    for (int i = 0; i < n; i++) {
      int left = k;
      for (int j = i + 1; j < 2 * n && left; j++) {
        left--;
        cout << (i + 1) << " " << (j % n) + 1 << "\n";
      }
    }
  } else
    cout << "-1\n";
  return 0;
}
