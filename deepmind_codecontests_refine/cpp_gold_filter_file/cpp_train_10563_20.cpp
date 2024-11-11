#include <bits/stdc++.h>
using namespace std;
map<string, string> A;
int main() {
  int n, m;
  cin >> n >> m;
  string a[3005];
  for (int i = 0; i < m; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() <= s2.size())
      A[s1] = s1;
    else
      A[s1] = s2;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cout << A[s] << " ";
  }
  return 0;
}
