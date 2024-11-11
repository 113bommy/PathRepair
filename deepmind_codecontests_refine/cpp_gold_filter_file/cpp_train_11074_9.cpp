#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> prime;
void creating_seive(bool a[], int n) {
  for (int i = 2; i <= (int)(pow(n, 0.5)); i++) {
    if (a[i] == 1) {
      int k = 0;
      for (int j = i * i; j <= n; j = i * i + k * i) {
        a[j] = 0;
        k++;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (a[i] == 1) {
      prime.push_back(i);
    }
  }
}
int main() {
  int n = 1e5 + 3;
  bool a[n + 1];
  for (int i = 0; i <= n; i++) {
    a[i] = 1;
  }
  creating_seive(a, n);
  int r, c;
  cin >> r >> c;
  int rmin = 1e5, sumr, sumc, cmin = 1e5;
  int arr[r][c];
  for (int i = 0; i < r; i++) {
    sumr = 0;
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
      int index =
          lower_bound(prime.begin(), prime.end(), arr[i][j]) - prime.begin();
      if (prime[index] > arr[i][j]) {
        sumr += prime[index] - arr[i][j];
      }
    }
    if (sumr <= rmin) {
      rmin = sumr;
    }
  }
  for (int j = 0; j < c; j++) {
    sumc = 0;
    for (int i = 0; i < r; i++) {
      int index =
          lower_bound(prime.begin(), prime.end(), arr[i][j]) - prime.begin();
      if (prime[index] > arr[i][j]) {
        sumc += prime[index] - arr[i][j];
      }
    }
    if (sumc <= cmin) {
      cmin = sumc;
    }
  }
  cout << min(cmin, rmin);
}
