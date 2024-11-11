#include <bits/stdc++.h>
using namespace std;
char a[100005];
int kmp[100005], f[100005];
vector<int> v;
int main(int argc, char** argv) {
  scanf("%s", a + 1);
  int n = strlen(a + 1);
  int now = 0;
  for (int i = 2; i <= n; i++) {
    while (now && a[now + 1] != a[i]) now = kmp[now];
    if (a[now + 1] == a[i]) ++now;
    kmp[i] = now;
  }
  now = n;
  while (now) v.push_back(now), now = kmp[now];
  for (int i = 1; i <= n; i++) ++f[kmp[i]];
  for (int i = 1; i <= n; i++) f[kmp[i]] += f[i];
  int ans;
  cout << (ans = v.size()) << "\n";
  for (int i = v.size() - 1; i >= 0; i--)
    cout << v[i] << " " << f[v[i]] + 1 << "\n";
  return 0;
}
