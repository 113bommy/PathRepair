#include <bits/stdc++.h>
using namespace std;
int a[105];
set<int> st;
vector<int> v;
int f[1000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x;
    v.clear();
    st.clear();
    for (int i = 0; i < n; i++) {
      cin >> y;
      if (!st.count(y)) {
        v.push_back(y);
      }
      st.insert(y);
    }
    for (int i = 1; i <= 1000; i++) {
      if (x > 0 && !st.count(i)) {
        v.push_back(i);
        x--;
      }
    }
    int mx = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      if (v[i] - v[i - 1] <= 1) {
        mx = ({
          int nos[] = {mx, v[i]};
          int n = sizeof(nos) / sizeof(int);
          *std::max_element(&nos[0], &nos[n]);
        });
      } else if (v[i] - v[i - 1] > 1) {
        break;
      }
    }
    cout << mx << endl;
  }
  return 0;
}
