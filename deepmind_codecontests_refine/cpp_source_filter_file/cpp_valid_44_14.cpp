#include <bits/stdc++.h>
using namespace std;
void show(int ans[], int n) {
  for (int i = (0); i < (n); ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int gcd(int a, int b) {
  while (a) {
    b %= a;
    a ^= b;
    b ^= a;
    a ^= b;
  }
  return b;
}
int tempa[10000];
void mergesort(int* a, int n1, int n2) {
  int a1, a2, n12;
  int i, j;
  if (n1 < n2) {
    n12 = (n1 + n2) / 2;
    mergesort(a, n1, n12);
    mergesort(a, n12 + 1, n2);
    for (i = n1; i <= n2; i++) {
      tempa[i] = a[i];
    }
    a1 = n1;
    a2 = n12 + 1;
    for (i = n1; (a1 <= n12 && a2 <= n2); i++) {
      if (tempa[a1] <= tempa[a2]) {
        a[i] = tempa[a1];
        a1++;
      } else {
        a[i] = tempa[a2];
        a2++;
      }
    }
    if (a1 > n12) {
      for (j = a2; j <= n2; j++, i++) {
        a[i] = tempa[j];
      }
    } else {
      for (j = a1; j <= n12; j++, i++) {
        a[i] = tempa[j];
      }
    }
  }
}
bool sorted(string arr, int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i + 1] != arr[i]) return false;
  }
  return true;
}
void bubbleSort(int* arr, int n) {
  for (int i = (0); i < (n); ++i) {
    for (int j = i; j < n; ++j) {
    }
  }
}
int solve() {
  int _test;
  cin >> _test;
  while (_test--) {
    int c, d, a = 0, b = 0;
    cin >> c >> d;
    if (c == d)
      cout << (c != 0) << "\n";
    else if (abs(c - d) == 1) {
      cout << (-1) << "\n";
    } else
      cout << (2) << "\n";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
