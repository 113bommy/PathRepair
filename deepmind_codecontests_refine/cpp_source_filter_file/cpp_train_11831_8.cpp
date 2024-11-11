#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5 + 2;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string kelma;
  int c = 0;
  cin >> kelma;
  for (int i = 0; i < (int)kelma.size(); i++) {
    if (kelma[i] == 'i' or kelma[i] == 'a' or kelma[i] == 'o' or
        kelma[i] == 'u' or kelma[i] == 'e')
      c++;
    else if (kelma[i] == '0' or kelma[i] == '2' or kelma[i] == '4' or
             kelma[i] == '6' or kelma[i] == '8')
      c++;
  }
  cout << c << "\n";
  return 0;
}
