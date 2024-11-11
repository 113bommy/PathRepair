#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[100009];
  char adj[100009];
  int l, i, h = 0;
  cin >> str;
  l = strlen(str);
  adj[h++] = str[l - 1];
  for (i = l - 2; i >= 0; i--) {
    if (str[i] >= adj[h - 1]) adj[h++] = str[i];
  }
  for (i = h - 1; i >= 0; i--) cout << adj[i];
  cout << endl;
  return 0;
}
