#include <bits/stdc++.h>
using namespace std;
void input() {}
int main() {
  input();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, start = 0, end = 0;
  cin >> n;
  string footprints;
  cin >> footprints;
  for (int i = 0; i < n; ++i) {
    if (footprints[i] != '.' && start == 0) {
      start = i + 1;
      end = i + 1;
    }
    if (footprints[i] == 'L') {
      end--;
      break;
    }
    if (footprints[i] == 'R') end++;
  }
  cout << start << " " << end;
}
