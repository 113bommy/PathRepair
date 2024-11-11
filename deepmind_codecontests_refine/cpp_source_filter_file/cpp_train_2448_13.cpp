#include <bits/stdc++.h>
using namespace std;
int r[200010], l[200010], one[200010], zero[200010];
int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size()) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < b.size(); i++) {
    if (b.size() - i >= a.size())
      l[i] = 1;
    else
      l[i] = a.size() - b.size() + i + 1;
    if (i + 1 >= a.size())
      r[i] = a.size();
    else
      r[i] = i + 1;
  }
  for (int i = 0; i < a.size(); i++)
    if (a[i] == '1') {
      one[i + 1] = one[i] + 1;
      zero[i + 1] = zero[i];
    } else {
      zero[i + 1] = zero[i] + 1;
      one[i + 1] = one[i];
    }
  for (int i = 0; i < b.size(); i++)
    if (b[i] == '1')
      ans += (long long)zero[r[i]] - zero[l[i] - 1];
    else
      ans += (long long)one[r[i]] - one[r[i] - 1];
  cout << ans << endl;
  return 0;
}
