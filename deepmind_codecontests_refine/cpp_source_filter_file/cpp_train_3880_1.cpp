#include <bits/stdc++.h>
using namespace std;
string s;
int ct1[10], ct2[10];
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) ct1[s[i] - '0']++;
  for (int i = 0; i < 10; i++) ct2[i] = ct1[i];
  int changed = 0, zero, start;
  int best = ct1[0];
  string b1 = s, b2 = s;
  sort(b1.rbegin(), b1.rend());
  sort(b2.rbegin(), b2.rend());
  for (int z = 0; z <= ct1[0]; z++)
    for (int i = 1; i < 10; i++)
      if (ct1[i] > 0 && ct2[10 - i] > 0) {
        ct1[0] -= z;
        ct2[0] -= z;
        ct1[i]--;
        ct2[10 - i]--;
        int get = z + 1;
        for (int j = 0; j < 5; j++) get += min(ct1[j], ct2[9 - j]);
        if (get > best) {
          best = get;
          changed = 1;
          zero = z;
          start = i;
        }
        ct1[0] += z;
        ct2[0] += z;
        ct1[i]++;
        ct2[10 - i]++;
      }
  if (changed) {
    string c1, c2;
    for (int i = 0; i < zero; i++) c1 += "0", c2 += "0";
    ct1[0] -= zero;
    ct2[0] -= zero;
    c1.push_back(start + '0');
    c2.push_back(10 - start + '0');
    ct1[start]--;
    ct2[10 - start]--;
    for (int j = 0; j < 5; j++) {
      int mn = min(ct1[j], ct2[9 - j]);
      for (int k = 0; k < mn; k++) {
        c1.push_back(j + '0');
        c2.push_back(9 - j + '0');
        ct1[j]--;
        ct2[9 - j]--;
      }
    }
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < ct1[i]; j++) c1.push_back(i + '0');
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < ct2[i]; j++) c2.push_back(i + '0');
    reverse(c1.begin(), c1.end());
    reverse(c2.begin(), c2.end());
    b1 = c1;
    b2 = c2;
  }
  cout << b1 << endl;
  cout << b2 << endl;
  return 0;
}
