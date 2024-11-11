#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  long long int ans = n * (n - 1) / 2;
  vector<int> aa;
  int now = 1;
  for (int i = (1); i < (n); i++) {
    if (s[i] == s[i - 1]) {
      now++;
    } else {
      aa.push_back(now);
      now = 1;
    }
  }
  aa.push_back(now);
  long long int tmp = 2 * n;
  tmp -= aa[0];
  tmp -= aa.back();
  tmp -= (aa.size() - 1);
  cout << ans - tmp << endl;
}
