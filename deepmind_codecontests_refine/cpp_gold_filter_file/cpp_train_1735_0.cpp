#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
unsigned long long n, a[MAXN + 5], three[MAXN + 5], two[MAXN + 5],
    ans[MAXN + 5];
bool cmp(int i, int j) {
  if (three[i] != three[j])
    return (three[i] > three[j]);
  else
    return (a[i] < a[j]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    unsigned long long tmp = a[i];
    while (tmp % 3 == 0) {
      three[i]++;
      tmp /= 3;
    }
  }
  for (int i = 0; i < n; i++) ans[i] = (unsigned long long)i;
  sort(ans, ans + n, cmp);
  for (int i = 0; i < n; i++) cout << a[ans[i]] << " ";
  cout << endl;
  return 0;
}
