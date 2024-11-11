#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;
vector<int> v;
bool check(int i) {
  int sh = (i + 1) / 2;
  int pa = (i) / 2;
  if (sh <= a and sh * k >= a and pa <= b and pa * k >= b) {
    for (int j = 1; j <= i; j++) v.push_back(1);
    a -= sh;
    b -= pa;
    for (int j = 0; j < i; j++) {
      if (j % 2 == 0) {
        while (a and v[j] < k) {
          a--;
          v[j]++;
        }
      } else {
        while (b and v[j] < k) {
          b--;
          v[j]++;
        }
      }
    }
    for (int j = 0; j < i; j++) {
      while (v[j] > 0) {
        v[j]--;
        if (j % 2 == 0)
          cout << 'G';
        else
          cout << 'B';
      }
    }
    return 1;
  }
  swap(a, b);
  if (sh <= a and sh * k >= a and pa <= b and pa * k >= b) {
    a -= sh;
    b -= pa;
    for (int j = 1; j <= i; j++) v.push_back(1);
    for (int j = 0; j < i; j++) {
      if (j % 2 == 0) {
        while (a and v[j] < k) {
          a--;
          v[j]++;
        }
      } else {
        while (b and v[j] < k) {
          b--;
          v[j]++;
        }
      }
    }
    for (int j = 0; j < i; j++) {
      while (v[j] > 0) {
        v[j]--;
        if (j % 2 == 0)
          cout << 'B';
        else
          cout << 'G';
      }
    }
    return 1;
  }
  swap(a, b);
  return 0;
}
int main() {
  cin >> n >> k >> a >> b;
  for (int i = 2; i <= n; i++) {
    if (check(i)) return 0;
  }
  cout << "NO";
  return 0;
}
