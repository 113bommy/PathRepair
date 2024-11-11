#include <bits/stdc++.h>
using namespace std;
string a;
long long t[300], f = 0;
vector<char> k;
int main() {
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '?') {
      k.push_back(a[i]);
      if (i == 0) f = 1;
    }
    if (a[i] >= 65 and a[i] <= 90) {
      if (!t[a[i]]) {
        k.push_back(a[i]);
      }
      t[a[i]]++;
      if (i == 0) f = 1;
    }
  }
  long long ans = 1;
  long long ty = 0;
  for (int i = 0; i < k.size(); i++) {
    if (k[i] == '?') {
      ans *= 10 - f;
      f = 0;
    } else {
      ans *= 10 - ty - f;
      f = 0;
      ty++;
    }
  }
  cout << ans << endl;
  return 0;
}
