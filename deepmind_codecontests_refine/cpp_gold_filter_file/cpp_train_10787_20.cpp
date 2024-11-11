#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
bool debug = 0;
const int N = 2e5 + 10;
int vmaxr[N], vmaxl[N], v[N], iref[N];
vector<int> vor[N];
int n;
int funcor(int l, int r) {
  l--;
  vector<int> vdif = vor[r];
  if (l >= 0) {
    for (int i = 0; i < vor[l].size(); i++) {
      vdif[i] -= vor[l][i];
    }
  }
  int ans = 0;
  int cur = 1;
  for (int i = 0; i < vdif.size(); i++) {
    if (vdif[i]) {
      ans += cur;
    }
    cur *= 2;
  }
  return ans;
}
int funcor2(int l, int r) {
  l--;
  vector<int> vdif = vor[r];
  if (l >= 0) {
    for (int i = 0; i < vor[l].size(); i++) {
      vdif[i] -= vor[l][i];
    }
  }
  int ans = 0;
  int cur = 1;
  for (int i = 0; i < vdif.size(); i++) {
    if (vdif[i]) {
      ans += cur;
    }
    cur *= 2;
  }
  return ans;
}
bool f(int pivo, int ii) {
  if (ii < 0 or pivo < 0 or ii >= n or pivo >= n) return 0;
  if (pivo == vmaxr[ii] or pivo == vmaxl[ii]) return 0;
  return ii < pivo ? v[ii] < funcor(min(ii, pivo), max(ii, pivo))
                   : v[ii] < funcor2(min(ii, pivo), max(ii, pivo));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
  }
  stack<int> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() and v[i] >= v[s.top()]) {
      vmaxr[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    vmaxr[s.top()] = n;
    s.pop();
  }
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() and v[i] > v[s.top()]) {
      vmaxl[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    vmaxl[s.top()] = -1;
    s.pop();
  }
  for (int i = 0; i < n; i++) {
    if (debug)
      cout << "i"
           << " = " << (i) << endl;
    if (debug)
      cout << "v[i]"
           << " = " << (v[i]) << endl;
    if (debug)
      cout << "vmaxr[i]"
           << " = " << (vmaxr[i]) << endl;
    if (debug)
      cout << "vmaxl[i]"
           << " = " << (vmaxl[i]) << endl;
    if (debug) cout << endl;
  }
  vector<int> vcur;
  for (int i = 0; i < n; i++) {
    int idx = 0;
    int x = v[i];
    while (x) {
      if (idx == vcur.size()) {
        vcur.push_back(x % 2);
      } else {
        vcur[idx] += x % 2;
      }
      idx++;
      x = x / 2;
    }
    vor[i] = vcur;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    iref[i] = vmaxr[i];
    int lo = i, hi = vmaxr[i];
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (f(mid, i)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (lo == vmaxr[i]) continue;
    if (f(lo, i)) {
      if (debug)
        cout << "i"
             << " = " << (i) << endl;
      iref[i] = lo;
      if (debug)
        cout << "lo"
             << " = " << (lo) << endl;
      if (debug)
        cout << "1ll * (vmaxr[i] - lo) * (i - vmaxl[i])"
             << " = " << (1ll * (vmaxr[i] - lo) * (i - vmaxl[i])) << endl;
      ans += 1ll * (vmaxr[i] - lo) * (i - vmaxl[i]);
    }
  }
  if (debug)
    cout << "ans"
         << " = " << (ans) << endl;
  for (int i = n - 1; i >= 0; i--) {
    int lo = vmaxl[i], hi = i;
    if (hi - lo <= 1) continue;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (!f(mid, i)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (lo == vmaxl[i]) continue;
    lo--;
    if (f(lo, i)) {
      if (debug) cout << endl;
      if (debug)
        cout << "v[i]"
             << " = " << (v[i]) << endl;
      if (debug)
        cout << "i"
             << " = " << (i) << endl;
      if (debug)
        cout << "lo"
             << " = " << (lo) << endl;
      if (debug)
        cout << "1ll * (-vmaxl[i] + lo)"
             << " = " << (1ll * (-vmaxl[i] + lo)) << endl;
      ans += 1ll * (-vmaxl[i] + lo) * (iref[i] - i);
    }
  }
  cout << ans << endl;
  return 0;
}
