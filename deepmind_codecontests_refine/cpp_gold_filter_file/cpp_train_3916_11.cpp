#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[10000];
  cin >> n >> k;
  int couples = n * 2;
  int fours = n;
  int oneOnly = 0;
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < k && fours > 0; ++i) {
    while (a[i] >= 3 && fours > 0) {
      a[i] -= 4;
      fours--;
    }
  }
  for (int i = 0; i < k && couples > 0; ++i) {
    while (a[i] > 1 && couples > 0) {
      a[i] -= 2;
      couples--;
    }
  }
  for (int i = 0; i < k && couples > 0; ++i) {
    while (a[i] == 1 && couples > 0) {
      a[i] -= 1;
      couples--;
    }
  }
  for (int i = 0; i < k && fours > 0; ++i) {
    while (a[i] == 2 && fours > 0) {
      a[i] -= 2;
      fours--;
      oneOnly++;
    }
  }
  for (int i = 0; i < k && fours > 0; ++i) {
    while (a[i] == 1 && fours > 0) {
      a[i] -= 1;
      fours--;
      oneOnly++;
    }
  }
  for (int i = 0; i < k && oneOnly > 0; ++i) {
    while (a[i] > 0 && oneOnly > 0) {
      a[i] -= 1;
      oneOnly--;
    }
  }
  for (int i = 0; i < k; ++i) {
    if (a[i] > 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
