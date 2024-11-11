#include <bits/stdc++.h>
using namespace std;
int test = 1;
int endTest = 25;
int sz = 5;
bool good(vector<int> v) {
  vector<int> t;
  int mp = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    if (i + 1 == v[i]) {
      t.push_back(i + 1);
      continue;
    }
    int cur = i;
    while (!(mp & (1 << cur))) {
      mp |= (1 << cur);
      t.push_back(v[cur]);
      cur = v[cur] - 1;
    }
  }
  if (t == v)
    return true;
  else
    return false;
}
vector<int> v;
vector<int> p;
void permute(int mp) {
  if (v.size() == sz) {
    if (good(v)) {
      for (int i = 0; i < sz; ++i) {
        cout << v[i] << " ";
      }
      cout << endl;
      if (test++ == endTest) exit(0);
    }
    return;
  }
  for (int i = 1; i <= sz; ++i) {
    if (!(mp & (1 << i))) {
      v.push_back(i);
      permute(mp | (1 << i));
      v.pop_back();
    }
  }
}
int main() {
  long long f[85];
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < 85; ++i) f[i] = f[i - 1] + f[i - 2];
  long long n, k;
  cin >> n >> k;
  vector<int> v;
  stack<int> s;
  for (int i = n; i >= 1; --i) s.push(i);
  for (int i = 1; i <= n; ++i) {
    if (k <= f[n - i]) {
      cout << (s.top()) << " ";
      s.pop();
    } else {
      k -= f[n - i];
      int r = s.top();
      s.pop();
      cout << (s.top()) << " ";
      s.pop(), s.push(r);
    }
  }
}
