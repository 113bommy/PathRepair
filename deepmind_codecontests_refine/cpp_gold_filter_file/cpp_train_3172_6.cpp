#include <bits/stdc++.h>
using namespace std;
long long po(long long number, long long power) {
  long long res = 1;
  for (int i = 0; i < power; i++) res *= number;
  return res;
}
int main() {
  int n;
  cin >> n;
  long long min_x = po(10, 9) + 1;
  long long min_y = po(10, 9) + 1;
  long long max_x = po(-10, 9) - 1;
  long long max_y = po(-10, 9) - 1;
  pair<long long, long long> point[1000];
  for (int i = 0; i < n; i++) {
    cin >> point[i].first;
    cin >> point[i].second;
    if (point[i].first < min_x) min_x = point[i].first;
    if (point[i].first > max_x) max_x = point[i].first;
    if (point[i].second < min_y) min_y = point[i].second;
    if (point[i].second > max_y) max_y = point[i].second;
  }
  cout << setprecision(19) << max(po(min_x - max_x, 2), po(min_y - max_y, 2));
}
