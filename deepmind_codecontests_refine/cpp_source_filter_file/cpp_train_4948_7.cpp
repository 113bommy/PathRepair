#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> b, a;
vector<int> ans;
int ans2[200500];
int ans3[200500];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0) continue;
    a.push_back(x);
  }
  int pos = -1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0) continue;
    b.push_back(x);
  }
  for (int i = 0; i < n - 1; i++)
    if (a[0] == b[i] && pos == -1) pos = i;
  for (int i = pos; i < n - 1; i++) ans.push_back(b[i]);
  for (int i = 0; i < pos; i++) ans.push_back(b[i]);
  bool f1 = 1;
  for (int i = 0; i < n; i++) {
    if (ans[i] != a[i]) f1 = 0;
  }
  if (f1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
