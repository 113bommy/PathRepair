#include <bits/stdc++.h>
using namespace std;
string a;
int cnt[31][31][10001], ans;
int main() {
  unsigned int i, j, k;
  cin >> a;
  int n = a.size();
  for (i = 0; i < n; i++) a[i] -= 'a';
  for (i = 0; i < n; i++) a.insert(a.end(), a[i]);
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n * 2; j++) cnt[a[i]][a[j]][j - i + 1]++;
  for (i = 'a'; i <= 'z'; i++) {
    int maxl = 0, sum;
    for (k = 1; k <= n; k++) {
      sum = 0;
      for (j = 'a'; j <= 'z'; j++)
        if (cnt[i - 'a'][j - 'a'][k] == 1) sum++;
      maxl = max(maxl, sum);
    }
    ans += maxl;
  }
  cout.setf(ios::fixed);
  cout << fixed << setprecision(15) << ans * 1.0 / n;
  return 0;
}
