#include <bits/stdc++.h>
using namespace std;
int k[3];
int t[3];
long long a[100010];
struct mydata {
  int idx;
  long long x;
  bool operator<(const mydata &r) const {
    if (x == r.x)
      return idx < r.idx;
    else
      return x < r.x;
  }
} b[100010];
std::priority_queue<long long, vector<long long>, greater<long long> > Q;
int main() {
  int i;
  cin >> k[0] >> k[1] >> k[2];
  cin >> t[0] >> t[1] >> t[2];
  int n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    b[i].x = a[i];
    b[i].idx = i;
  }
  for (i = 0; i < n; i++) {
    if (k[0] > 0) {
      b[i].x += t[0];
      Q.push(b[i].x);
      k[0]--;
    } else {
      long long x = Q.top();
      Q.pop();
      b[i].x = max(x, b[i].x) + t[0];
      Q.push(b[i].x);
    }
  }
  while (!Q.empty()) Q.pop();
  sort(b, b + n);
  for (i = 0; i < n; i++) {
    if (k[1] > 0) {
      b[i].x += t[1];
      Q.push(b[i].x);
      k[1]--;
    } else {
      long long x = Q.top();
      Q.pop();
      b[i].x = max(x, b[i].x) + t[1];
      Q.push(b[i].x);
    }
  }
  while (!Q.empty()) Q.pop();
  sort(b, b + n);
  for (i = 0; i < n; i++) {
    if (k[2] > 0) {
      b[i].x += t[2];
      Q.push(b[i].x);
      k[2]--;
    } else {
      long long x = Q.top();
      Q.pop();
      b[i].x = max(x, b[i].x) + t[2];
      Q.push(b[i].x);
    }
  }
  while (!Q.empty()) Q.pop();
  sort(b, b + n);
  long long ret = 0;
  for (i = 0; i < n; i++) {
    if (ret < b[i].x - a[b[i].idx]) ret = b[i].x - a[b[i].idx];
  }
  cout << ret << endl;
  return 0;
}
