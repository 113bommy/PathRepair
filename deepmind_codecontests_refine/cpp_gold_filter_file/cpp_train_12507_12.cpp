#include <bits/stdc++.h>
using namespace std;
int chapters[1000][4];
int main() {
  int n, current_page, index = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> chapters[i][0] >> chapters[i][1];
  cin >> current_page;
  while (chapters[index][0] <= current_page && index < n) index++;
  cout << (n - index + 1) << endl;
  return 0;
}
