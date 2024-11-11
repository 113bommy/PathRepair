#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int n, d;
long long x;
int a[N], b[N], c[N], pos[N];
vector<int> tmp;
set<int> q;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i++) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int main() {
  cin >> n >> d >> x;
  initAB();
  if (d < 4000) {
    for (int i = 0; i < n; i++) {
      if (b[i] == 1) tmp.push_back(i);
      for (int j = 0; j < tmp.size(); j++) {
        c[i] = max(c[i], a[i - j]);
      }
    }
  } else {
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    for (int i = 0; i < n; i++) {
      q.insert(-a[i]);
      for (auto it = q.begin(); it != q.end(); it++) {
        int x = -(*it);
        if (b[i - pos[x]] != 0) {
          c[i] = x;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) cout << c[i] << " ";
  return 0;
}
