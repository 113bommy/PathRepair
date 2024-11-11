#include <bits/stdc++.h>
using namespace std;
string s;
int num[50] = {0};
int main() {
  int n, k;
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < s.size(); i++) num[s[i] - 'a'] = 1;
  int sum = 0, d = 0;
  for (int i = 0; i < 26; i++) {
    if (d == k) break;
    if (num[i]) {
      sum += (i + 1);
      i++;
      d++;
    }
  }
  if (d != k)
    cout << -1 << endl;
  else
    cout << sum << endl;
}
