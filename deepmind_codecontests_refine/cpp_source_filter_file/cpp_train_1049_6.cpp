#include <bits/stdc++.h>
using namespace std;
vector<int> ad[400001];
vector<int> ad1[400001];
int n1 = 0, n, k;
void dfs(int no, int va) {
  int c = ad[no].size();
  while (n1 < n && c < k && va > 0) {
    n1++;
    c++;
    ad[no].push_back(n1);
    ad[n1].push_back(no);
    dfs(n1, va - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int d;
  cin >> n >> d >> k;
  if (n - 1 < d || (n > 1 && k < 2)) {
    cout << "NO"
         << "\n";
  } else {
    n--;
    for (int i = 0; i < d; i++) {
      ad[i].push_back(i + 1);
      ad[i + 1].push_back(i);
    }
    n1 = d;
    for (int i = 1; i < d; i++) {
      if (n1 == n) {
        break;
      }
      dfs(i, min(i, d - i));
    }
    if (n <= n1) {
      cout << "YES"
           << "\n";
      for (int i = 0; i < n1; i++) {
        for (int j = 0; j < ad[i].size(); j++) {
          if (ad[i][j] > i) {
            cout << i + 1 << " " << ad[i][j] + 1 << "\n";
          }
        }
      }
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
