#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, m, times = 0;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> m;
    vector<int> vec(m);
    for (int j = 0; j < m; ++j) {
      cin >> vec[j];
    }
    for (int j = 0; j < m - 1; ++j) {
      if (vec[j] == 1) {
        int k = j + 1;
        while (k < m) {
          if (vec[k] - vec[j] == 1) {
            j++, k++;
          } else {
            ++times;
            break;
          }
        }
      } else {
        ++times;
      }
    }
  }
  cout << times * 2 + k - 1 << endl;
  return 0;
}
