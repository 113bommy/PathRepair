#include <bits/stdc++.h>
using namespace std;
const int NN = 2010101;
long long a[NN], b[NN], cnt[NN], fsum[NN], ff[NN];
int id[NN], fcnt[NN];
set<long long> s;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%I64d", b + i);
    cnt[b[i]]++;
  }
  id[1] = 1;
  for (int i = 2; i <= 4 * (m + n); i++) {
    if (id[i - 1] == n)
      id[i] = n - 1;
    else if (id[i - 1] == 1)
      id[i] = 2;
    else if (id[i - 1] > id[i - 2])
      id[i] = id[i - 1] + 1;
    else
      id[i] = id[i - 1] - 1;
  }
  long long sum = 0;
  for (int i = 2; i <= m; i++) {
    sum = sum + abs(a[id[i]] - a[id[i - 1]]);
  }
  for (int i = 1; i <= m; i++) {
    fcnt[id[i]]++;
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (fcnt[i] != cnt[i]) flag++;
  }
  if (flag == 0) s.insert(sum);
  int st = 1;
  int ed = id[m];
  for (int i = 2; i <= n + m + 2; i++) {
    sum -= abs(a[st] - a[id[i]]);
    sum += abs(a[ed] - a[id[i - 1 + m]]);
    st = id[i - 1];
    fcnt[st]--;
    if (fcnt[st] == cnt[st])
      flag--;
    else if (fcnt[st] + 1 == cnt[st])
      flag++;
    ed = id[i - 1 + m];
    fcnt[ed]++;
    if (fcnt[ed] == cnt[ed])
      flag--;
    else if (fcnt[ed] - 1 == cnt[ed])
      flag++;
    if (flag == 0) s.insert(sum);
    st = id[i];
  }
  if (s.size() == 0 || s.size() > 1)
    puts("-1");
  else
    cout << *s.begin() << endl;
  return 0;
}
