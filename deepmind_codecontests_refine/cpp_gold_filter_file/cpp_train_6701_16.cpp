#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> s, p, q;
vector<int> op1(vector<int> p) {
  vector<int> ans;
  for (int i = (0), _b = (n); i <= _b; i++) ans.push_back(0);
  for (int i = (1), _b = (n); i <= _b; i++) ans[i] = p[q[i]];
  return ans;
}
vector<int> op2(vector<int> p) {
  vector<int> ans;
  for (int i = (0), _b = (n); i <= _b; i++) ans.push_back(0);
  for (int i = (1), _b = (n); i <= _b; i++) ans[q[i]] = p[i];
  return ans;
}
int main() {
  cin >> n >> k;
  q.push_back(0);
  s.push_back(0);
  p.push_back(0);
  int v;
  for (int i = (1), _b = (n); i <= _b; i++) {
    cin >> v;
    q.push_back(v);
  }
  for (int i = (1), _b = (n); i <= _b; i++) {
    cin >> v;
    s.push_back(v);
  }
  int i1, i2;
  bool ok1 = false, ok2 = false;
  for (int i = (1), _b = (n); i <= _b; i++) p.push_back(i);
  if (p == s) {
    cout << "NO";
    return 0;
  }
  for (i1 = 1; i1 <= k; i1++) {
    p = op1(p);
    if (p == s) {
      ok1 = true;
      break;
    }
  }
  for (int i = (1), _b = (n); i <= _b; i++) p[i] = i;
  for (i2 = 1; i2 <= k; i2++) {
    p = op2(p);
    if (p == s) {
      ok2 = true;
      break;
    }
  }
  if ((ok1 && (i1 == k)) || (ok2 && (i2 == k))) {
    cout << "YES";
    return 0;
  }
  if ((i1 == 1) && (i2 == 1)) {
    cout << "NO";
    return 0;
  }
  if ((ok1 && ((k - i1) % 2 == 0)) || (ok2 && ((k - i2) % 2 == 0))) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
