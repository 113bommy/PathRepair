#include <bits/stdc++.h>
using namespace std;
int xx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int yy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};
long long int gcd(long long int a, long long int b) {
  return ((a % b == 0) ? b : gcd(b, a % b));
}
bool comp(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
int main() {
  int n, len, i, pos, j, k;
  string str;
  cin >> n;
  cin >> str;
  pos = n + 10;
  for (i = 0; i < n; i++) {
    if (str[i] == '*') {
      pos = i;
      break;
    }
  }
  bool f = false, ff = false;
  int count = 0;
  for (k = 0; k < n; k++) {
    if (str[k] == '*') {
      pos = k;
      for (i = 1; i <= n; i++) {
        f = true;
        ff = false;
        count = 0;
        for (j = pos; j < n; j = j + i) {
          ff = true;
          if (str[j] != '*') {
            f = false;
          }
          count++;
          if (f && ff && count >= 4) {
            cout << "yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "no" << endl;
  return 0;
}
