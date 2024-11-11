#include <bits/stdc++.h>
using namespace std;
int c[200005];
int d[200005];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> c[i] >> d[i];
  }
  long long rating = 0, min1 = 200000000000000, max2 = -200000000000000;
  bool set2 = false, set1 = false;
  if (d[0] == 1) {
    rating = 1900;
    min1 = 1900;
    set1 = true;
  } else {
    set2 = true;
    rating = 1899;
    max2 = 1899;
  }
  long long i = 1;
  for (i = 1; i < n; i++) {
    if (d[i] == 1) {
      set1 = true;
      min1 = min(min1, rating + c[i - 1]);
    } else {
      set2 = true;
      max2 = max(max2, rating + c[i - 1]);
    }
    rating += c[i - 1];
  }
  rating += c[i - 1];
  if (set1 && set2 && (min1 < max2)) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (set2 == false) {
    cout << "Infinity" << endl;
    return 0;
  }
  long long add = 1899 - max2;
  cout << rating + add << endl;
  return 0;
}
