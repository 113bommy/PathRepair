#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char color[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
  int x(0);
  for (int i = 0; i < n; i++) {
    if (x == 7) x = 3;
    cout << color[x];
    x++;
  }
}
