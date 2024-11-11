#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v) cin >> it;
  string s;
  cin >> s;
  sort((v).begin(), (v).end());
  int x = 0;
  for (long long i = 0; i < s.length() - 1; i++) {
    if (s[i + 1] != s[i]) x++;
  }
  int left = n - x - 1, right = n - x - 1;
  cout << v[left] << " " << s[0] << "\n";
  int i = 1;
  char rpos = s[0], lpos = s[0];
  while (i != s.length()) {
    if (s[i] == s[i - 1]) {
      left--;
      if (lpos == 'R')
        lpos == 'L';
      else
        lpos == 'R';
      cout << v[left] << " " << lpos << "\n";
    } else {
      right++;
      if (rpos == 'R')
        rpos == 'L';
      else
        rpos == 'R';
      cout << v[right] << " " << rpos << "\n";
    }
    i++;
  }
  return 0;
}
