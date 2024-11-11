#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i = 0, j = 0;
  cin >> n >> m;
  int min = n / m;
  int left = n - min * m;
  if (left != 0) {
    for (i = 0; i < m - left; i++) cout << min << " ";
    for (int j = i; j < m - 1; j++) cout << min + 1 << " ";
    cout << min + 1 << endl;
  } else {
    for (int i = 0; i < m - 1; i++) cout << min << " ";
    cout << min << endl;
  }
  return 0;
}
