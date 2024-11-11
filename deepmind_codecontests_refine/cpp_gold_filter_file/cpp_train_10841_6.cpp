#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
  int n;
  cin >> n;
  vector<int> mas(n);
  for (size_t i = 0; i < n; i++) {
    cin >> mas[i];
  }
  int j = n - 1;
  while (mas[0] == mas[j]) {
    j--;
  }
  int j2 = 0;
  while (mas[n - 1] == mas[j2]) {
    j2++;
  }
  cout << max(j, n - j2 - 1);
  return 0;
}
