#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pq_gt = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pq_lt = priority_queue<T, vector<T>, less<T>>;
int a[6000], c[6000];
int b[6000];
int p[6000];
int ans[6000];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "? 0 " << i << endl;
    fflush(stdout);
    cin >> a[i];
  }
  for (int i = 1; i + 1 < n; i++) {
    cout << "? " << i << " " << i + 1 << endl;
    fflush(stdout);
    cin >> c[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    p[0] = i;
    bool flag = true;
    for (int j = 0; j < n; ++j) {
      b[j] = a[j] ^ p[0];
      if (b[j] >= n) {
        flag = false;
      }
    }
    for (int j = 0; j < n; ++j) {
      p[b[j]] = j;
    }
    for (int j = 1; j + 1 < n; ++j) {
      if (p[j] ^ b[j + 1] != c[i]) {
        flag = false;
      }
    }
    if (p[0] == i && flag) {
      cnt++;
      for (int j = 0; j < n; ++j) {
        ans[j] = p[j];
      }
    }
  }
  cout << "!" << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
