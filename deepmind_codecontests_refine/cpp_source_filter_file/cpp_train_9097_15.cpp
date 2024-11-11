#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<int>& v1, const vector<int>& v2) {
  return v1[0] < v2[0];
}
long long poww(long long i) {
  if (i == 0)
    return 1;
  else
    return 3 * poww(i - 1);
}
int main() {
  long long n;
  cin >> n;
  if (n % 3 == 0) {
    for (long long i = 1; i < n; i++) {
      if (n == poww(i)) {
        cout << 1;
        return 0;
      }
      if (n % poww(i)) {
        cout << n / poww(i);
        return 0;
      }
    }
  } else
    cout << n / 3 + 1;
  return 0;
}
