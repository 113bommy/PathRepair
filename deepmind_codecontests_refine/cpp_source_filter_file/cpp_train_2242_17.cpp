#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
bool visited[100005];
int main() {
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long p = 0;
  visited[0] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '>')
      p += a[i];
    else if (s[i] == '<')
      p -= a[i];
    if (p < 1 || p > n) {
      cout << "FINITE";
      return 0;
    }
    if (visited[p]) {
      cout << "INFINITE";
      return 0;
    }
    visited[p] = 1;
  }
  cout << "INFINITE";
  return 0;
}
