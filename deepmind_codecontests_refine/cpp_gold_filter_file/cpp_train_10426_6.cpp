#include <bits/stdc++.h>
using namespace std;
int sex[100010];
int t[100010];
int main() {
  string s;
  int cnt = -1;
  while (cin >> s) {
    cnt++;
    sex[cnt] = 0;
    t[cnt] = 0;
    if (s.size() >= 4 && s.substr(s.size() - 4) == "lios") {
      sex[cnt] = 1;
      t[cnt] = 1;
      continue;
    }
    if (s.size() >= 5 && s.substr(s.size() - 5) == "liala") {
      sex[cnt] = 2;
      t[cnt] = 1;
      continue;
    }
    if (s.size() >= 3 && s.substr(s.size() - 3) == "etr") {
      sex[cnt] = 1;
      t[cnt] = 2;
      continue;
    }
    if (s.size() >= 4 && s.substr(s.size() - 4) == "etra") {
      sex[cnt] = 2;
      t[cnt] = 2;
      continue;
    }
    if (s.size() >= 6 && s.substr(s.size() - 6) == "initis") {
      sex[cnt] = 1;
      t[cnt] = 3;
      continue;
    }
    if (s.size() >= 6 && s.substr(s.size() - 6) == "inites") {
      sex[cnt] = 2;
      t[cnt] = 3;
      continue;
    }
  }
  cnt++;
  if (cnt == 1) {
    if (sex[0] > 0 && t[0] > 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  int p = sex[0];
  for (int i = 0; i < cnt; i++)
    if (p != sex[i] || sex[i] == 0 || t[i] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  bool ok = false;
  int q = 0;
  if (t[0] == 2) q++;
  for (int i = 1; i < cnt; i++) {
    if (t[i] == 2) q++;
    if (t[i] == t[i - 1]) continue;
    if (t[i] < t[i - 1]) {
      cout << "NO" << endl;
      return 0;
    }
    if (t[i] - t[i - 1] > 1) {
      cout << "NO";
      return 0;
    }
  }
  if (q == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
