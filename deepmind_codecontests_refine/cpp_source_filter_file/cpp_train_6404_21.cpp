#include <bits/stdc++.h>
using namespace std;
void solve() {
  char s[100];
  cin >> s;
  char t[100];
  cin >> t;
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    for (int j = i; j <= i; j++) {
      int x = (int(s[i])) ^ (int(t[j]));
      cout << x;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  { solve(); }
}
