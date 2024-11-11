#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 3;
const long long max_val = 2e5 + 10;
long long mod = 1e9 + 7;
const long long bits = 20;
long long caseNumber = 1;
void jabru() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int l = 0, r = n - 1;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    string kk = a;
    for (int j = 0; j < mid; j++) {
      kk[v[j] - 1] = '@';
    }
    string k = "";
    for (int j = 0; j < n; j++) {
      if (kk[j] != '@') k += kk[j];
    }
    int st = 0;
    for (int i = 0; i < k.size(); i++) {
      if (st == b.size()) {
        break;
      } else {
        if (b[st] == k[i]) {
          st++;
        }
      }
    }
    if (st == b.size()) {
      l = mid;
    } else {
      r = mid;
    }
  }
  string kk = a;
  for (int j = 0; j < l; j++) {
    kk[v[j] - 1] = '@';
  }
  string k = "";
  for (int j = 0; j < n; j++) {
    if (kk[j] != '@') k += kk[j];
  }
  int st = 0;
  for (int i = 0; i < k.size(); i++) {
    if (st == b.size()) {
      break;
    } else {
      if (b[st] == k[i]) {
        st++;
      }
    }
  }
  if (st == b.size()) {
    cout << l << endl;
    return;
  }
  cout << r << endl;
  return;
}
bool TestCase = 0;
bool isGoogles = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  t = 1;
  if (TestCase) {
    cin >> t;
  }
  while (t--) {
    if (isGoogles) {
      cout << "Case #" << caseNumber << ": ";
    }
    caseNumber++;
    jabru();
  }
  return 0;
}
