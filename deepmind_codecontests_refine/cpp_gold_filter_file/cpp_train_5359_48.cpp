#include <bits/stdc++.h>
using namespace std;
bool com(string a, string b) {
  if (a.size() > b.size()) return false;
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  int b, g;
  cin >> b;
  int boys[n];
  int ind;
  memset(boys, -1, sizeof boys);
  for (int i = 0; i < b; i++) {
    cin >> ind;
    boys[ind] = 1;
  }
  cin >> g;
  int girls[m];
  memset(girls, -1, sizeof girls);
  for (int i = 0; i < g; i++) {
    cin >> ind;
    girls[ind] = 1;
  }
  int days = n * m * n * m;
  for (int i = 0; i < days; i++) {
    if (boys[i % n] == 1 || girls[i % m] == 1)
      boys[i % n] = 1, girls[i % m] = 1;
  }
  for (int i = 0; i < n; i++)
    if (boys[i] == -1) {
      cout << "No";
      return 0;
    }
  for (int i = 0; i < m; i++)
    if (girls[i] == -1) {
      cout << "No";
      return 0;
    }
  cout << "Yes";
}
