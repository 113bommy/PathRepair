#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, x[2], need[N][2];
pair<int, int> p[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> x[0] >> x[1];
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    p[i] = {c, i};
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++) {
      int c = p[i].first;
      need[i][j] = (x[j] + c - 1) / c;
    }
  for (int i = n - 1; i >= 0; i--) {
    if (i + need[i][0] < n && need[i][0] + need[i + need[i][0]][1] <= n - i) {
      vector<int> a, b;
      for (int j = i; j < i + need[i][0]; j++) a.push_back(p[j].second);
      for (int j = i + need[i][0]; j < i + need[i][0] + need[i + need[i][0]][1];
           j++)
        b.push_back(p[j].second);
      cout << "Yes\n";
      cout << a.size() << " " << b.size() << "\n";
      for (int x : a) cout << x + 1 << " ";
      cout << "\n";
      for (int x : b) cout << x + 1 << " ";
      cout << "\n";
      return 0;
    }
    if (i + need[i][1] < n && need[i][1] + need[i + need[i][1]][0] <= n - i) {
      vector<int> a, b;
      for (int j = i; j < i + need[i][1]; j++) b.push_back(p[j].second);
      for (int j = i + need[i][1]; j < i + need[i][0] + need[i + need[i][1]][1];
           j++)
        a.push_back(p[j].second);
      cout << "Yes\n";
      cout << a.size() << " " << b.size() << "\n";
      for (int x : a) cout << x + 1 << " ";
      cout << "\n";
      for (int x : b) cout << x + 1 << " ";
      cout << "\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
