#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  long long int a[s.size()];
  vector<long long int> v;
  for (long long int i = 0; i < s.size(); i++) {
    if (i == 0) {
      vector<long long int> tp(8, 0);
      long long int j = 0;
      long long int k = s[i];
      while (k) {
        tp[j] = (k >> 0) & 1;
        k = k >> 1;
        j++;
      }
      long long int ans = 0;
      reverse(tp.begin(), tp.end());
      for (long long int l = 0; l < 8; l++) {
        ans = ans + tp[l] * pow(2, l);
      }
      v.push_back(ans);
      a[i] = 256 - ans;
      continue;
    }
    vector<long long int> tp(8, 0);
    long long int j = 0;
    long long int k = s[i];
    while (k) {
      tp[j] = (k >> 0) & 1;
      k = k >> 1;
      j++;
    }
    long long int ans = 0;
    reverse(tp.begin(), tp.end());
    for (long long int l = 0; l < 8; l++) {
      ans = ans + tp[l] * pow(2, l);
    }
    a[i] = (v[i - 1] - ans + 256) % 256;
    v.push_back(ans);
  }
  for (long long int i = 0; i < s.size(); i++) cout << a[i] << "\n ";
  return 0;
}
