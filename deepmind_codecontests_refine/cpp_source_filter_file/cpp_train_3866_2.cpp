#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
void Compute(long long int n, string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if ((s[0] == ')')) {
    s[0] = '(';
    stack<char> stk;
    bool ok = true;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push('(');
      } else {
        if (stk.empty()) {
          ok = false;
          break;
        } else
          stk.pop();
      }
    }
    if (!stk.empty()) {
      ok = false;
    }
    if (ok)
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  } else if (s[n - 1] == '(') {
    s[0] = ')';
    stack<char> stk;
    bool ok = true;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push('(');
      } else {
        if (stk.empty()) {
          ok = false;
          break;
        } else
          stk.pop();
      }
    }
    if (!stk.empty()) {
      ok = false;
    }
    if (ok)
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  } else {
    vector<long long int> pre(n);
    vector<long long int> suf(n);
    pre[0] = 1;
    suf[n - 1] = -1;
    for (long long int i = 1; i < n; i++) {
      pre[i] = pre[i - 1];
      if (s[i] == '(')
        pre[i]++;
      else
        pre[i]--;
    }
    for (long long int k = n - 2; k >= 0; k--) {
      suf[k] = suf[k + 1];
      if (s[k] == '(')
        suf[k]++;
      else
        suf[k]--;
    }
    vector<long long int> premin(n), sufmax(n);
    premin[0] = 1, sufmax[n - 1] = -1;
    for (long long int i = 1; i < n; i++) {
      premin[i] = min(premin[i - 1], pre[i]);
    }
    for (long long int k = n - 2; k >= 0; k--) {
      sufmax[k] = max(sufmax[k + 1], suf[k]);
    }
    long long int cnt = 0;
    for (long long int i = 1; i < n - 1; i++) {
      if ((premin[i - 1] >= 0) and (sufmax[i + 1] <= 0)) {
        if (s[i] == '(') {
          if ((pre[i - 1] - 1 + suf[i + 1]) == 0) cnt++;
        } else {
          if ((pre[i - 1] + 1 + suf[i + 1]) == 0) cnt++;
        }
      }
    }
    cout << cnt << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  string s;
  cin >> n >> s;
  Compute(n, s);
}
