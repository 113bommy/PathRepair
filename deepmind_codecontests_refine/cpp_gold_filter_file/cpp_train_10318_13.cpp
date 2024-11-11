#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn], cnt[maxn];
int ans[maxn], A, B;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
  for (int i = 0; i < n; i++)
    if (cnt[a[i]] == 1)
      if (A > B)
        ans[i] = 2, B++;
      else
        ans[i] = 1, A++;
    else if (cnt[a[i]] == 2)
      ans[i] = 1;
  for (int i = 0; i < n; i++)
    if (!ans[i])
      if (A > B)
        ans[i] = 2, B++;
      else
        ans[i] = 1;
  if (A != B) return cout << "NO", 0;
  cout << 'Y' << 'E' << 'S' << endl;
  for (int i = 0; i < n; i++)
    if (ans[i] == 1)
      cout << 'A';
    else
      cout << 'B';
  return 0;
}
