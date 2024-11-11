#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) cout << ((i + 1) % n + 1) << " ";
  return 0;
}
