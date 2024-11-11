#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> Height(n);
  vector<int> count(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> Height[i];
  }
  int x = 0, after = 1, befor = 0;
  while (after < n && Height[x] >= Height[after]) {
    count[0]++;
    x++;
    after++;
  }
  for (int i = 1; i < n - 1; i++) {
    x = i, after = i + 1, befor = i - 1;
    while (befor >= 0 && Height[x] >= Height[befor]) {
      count[i]++;
      x--;
      befor--;
    }
    x = i;
    while (after < n && Height[x] >= Height[after]) {
      count[i]++;
      x++;
      after++;
    }
  }
  x = n - 1;
  befor = n - 2;
  while (befor >= 0 && Height[x] >= Height[befor]) {
    count[n - 1]++;
    x--;
    befor--;
  }
  sort(count.begin(), count.end());
  cout << count[count.size() - 1] + 0;
  return 0;
}
