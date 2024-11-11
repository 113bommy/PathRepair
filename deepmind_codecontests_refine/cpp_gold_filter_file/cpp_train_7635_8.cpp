#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> dif[N];
int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int p;
      cin >> p;
      dif[i].push_back(p);
    }
    sort(dif[i].begin(), dif[i].end());
  }
  for (int i = 0; i < n; i++) {
    int p1 = 0, p2 = 0, n1 = (i ? i - 1 : n - 1), n2 = (i + 1) % n;
    for (int j = 1; j < (int)(dif[i]).size(); j++) {
      while (p1 < (int)(dif[n1]).size() && dif[n1][p1] < dif[i][j - 1]) p1++;
      while (p2 < (int)(dif[n2]).size() && dif[n2][p2] < dif[i][j - 1]) p2++;
      int mem1 = p1, mem2 = p2;
      while (p1 < (int)(dif[n1]).size() && dif[n1][p1] < dif[i][j]) p1++;
      while (p2 < (int)(dif[n2]).size() && dif[n2][p2] < dif[i][j]) p2++;
      if (p1 - mem1 != p2 - mem2) res++;
    }
  }
  cout << res << endl;
  return 0;
}
