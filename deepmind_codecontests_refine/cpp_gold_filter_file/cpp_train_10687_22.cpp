#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int main() {
  file();
  fast();
  int n, k;
  cin >> n >> k;
  while (k--) {
    if (n % 10)
      n--;
    else
      n /= 10;
  }
  cout << n << "\n";
  return 0;
}
