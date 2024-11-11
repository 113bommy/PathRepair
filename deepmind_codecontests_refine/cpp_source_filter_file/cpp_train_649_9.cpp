#include <bits/stdc++.h>
using namespace std;
int ans, a[20], b[20], ind = -1;
vector<int> v, u;
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) a[s[i] - '0']++;
  for (int i = 0; i < 10; i++) b[i] = a[i];
  for (int i = 1, c = 0; i < 6; c = 0, i++) {
    a[i]--;
    if (10 - i != i) a[10 - i]--;
    if (a[i] >= 0 && a[10 - i] >= 0) {
      c++;
      for (int j = 0; j < 5; j++) c += min(a[j], a[9 - j]) * 2;
    }
    if (c > ans) {
      ans = c;
      ind = i;
    }
    a[i]++;
    if (i != 10 - i) a[10 - i]++;
  }
  if (ind == -1)
    for (int i = 0; i < 10; i++)
      while (a[i]) {
        v.push_back(i);
        u.push_back(i);
        a[i]--;
        b[i]--;
      }
  else {
    int c = a[0] - (a[9] * 2 - (ind == 1));
    for (int i = 0; i < c; i++) {
      v.push_back(0);
      u.push_back(0);
      a[0]--;
      b[0]--;
    }
    v.push_back(ind);
    u.push_back(10 - ind);
    a[ind]--;
    b[10 - ind]--;
    for (int i = 0; i < 10; i++) {
      int c = min(a[i], b[9 - i]);
      a[i] -= c;
      b[9 - i] -= c;
      for (int j = 0; j < c; j++) {
        v.push_back(i);
        u.push_back(9 - i);
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < a[i]; j++) v.push_back(i);
      for (int j = 0; j < b[i]; j++) u.push_back(i);
    }
  }
  for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
  cout << endl;
  for (int i = u.size() - 1; i >= 0; i--) cout << u[i];
  cout << endl;
  return 0;
}
