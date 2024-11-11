#include <bits/stdc++.h>
using namespace std;
string dict[100];
string names[60];
int main() {
  int n, k;
  cin >> n >> k;
  string c = "abcde";
  for (int i = 0; i < 100; i++) {
    dict[i] = 'A' + c;
    next_permutation(c.begin(), c.end());
  }
  string s;
  cin >> s;
  int t = 0;
  if (s == "YES") {
    for (int i = 0; i < k; i++) names[i] = dict[t], t++;
  } else {
    for (int i = 0; i < k - 1; i++) names[i] = dict[t], t++;
    names[k - 1] = dict[0];
  }
  int pos = k;
  for (int i = 0; i < n - k; i++) {
    cin >> s;
    if (s == "YES") {
      names[pos] = dict[t], t++, pos++;
    } else {
      names[pos] = names[pos - k], pos++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << names[i] << ' ';
  }
  cout << endl;
  return 0;
}
