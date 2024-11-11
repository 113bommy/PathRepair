#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
vector<int> a, b;
int main() {
  cin >> s;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < (int)s.size(); ++i) cnt[s[i] - '0']++;
  int ans = 0, posi = -1;
  for (int i = 1; i <= 5; ++i) {
    int j = 10 - i;
    if (cnt[i] == 0 || cnt[j] == 0) continue;
    int a1[10], a2[10];
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    for (int k = 0; k < 10; ++k) a1[k] = a2[k] = cnt[k];
    a1[i]--;
    a2[j]--;
    int cur = 1;
    for (int k = 0; k <= 9; ++k) {
      int x = min(a1[k], a2[9 - k]);
      cur += x;
      a1[k] -= x;
      a2[9 - k] -= x;
    }
    cur += min(a1[0], a2[0]);
    if (ans < cur) {
      ans = cur;
      posi = i;
    }
  }
  a.clear();
  b.clear();
  if (posi == -1) {
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < cnt[i]; ++j) {
        a.push_back('0' + i);
        b.push_back('0' + i);
      }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
  } else {
    int a1[10], a2[10];
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    for (int i = 0; i < 10; ++i) a1[i] = a2[i] = cnt[i];
    --a1[posi];
    --a2[10 - posi];
    a.push_back('0' + posi);
    b.push_back('0' + 10 - posi);
    for (int k = 0; k <= 9; ++k) {
      int x = min(a1[k], a2[9 - k]);
      a1[k] -= x;
      a2[9 - k] -= x;
      for (int i = 0; i < x; ++i) {
        a.push_back('0' + k);
        b.push_back('0' + 9 - k);
      }
    }
    int x = min(a1[0], a2[0]);
    a1[0] -= x;
    a2[0] -= x;
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < a1[i]; ++j) a.push_back('0' + i);
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < a1[i]; ++j) a.push_back('0' + i);
    reverse(a.begin(), a.end());
    reverse(a.begin(), b.end());
    for (int i = 0; i < x; ++i) {
      a.push_back('0');
      b.push_back('0');
    }
  }
  for (int i = 0; i < (int)a.size(); ++i) cout << a[i];
  cout << endl;
  for (int i = 0; i < (int)a.size(); ++i) cout << b[i];
  cout << endl;
  return 0;
}
