#include <bits/stdc++.h>
using namespace std;
void printprecise(double l, long long int precision) {
  std::cout << std::fixed;
  std::cout << std::setprecision(precision);
  std::cout << l << endl;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int root(int ar[], int i) {
  while (ar[i] != i) {
    ar[i] = ar[ar[i]];
    i = ar[i];
  }
  return i;
}
void dsu(int ar[], int size[], int a, int b) {
  int root_a = root(ar, a);
  int root_b = root(ar, b);
  if (size[root_a] < size[root_b]) {
    ar[root_a] = root_b;
    size[root_b] = size[root_b] + size[root_a];
  } else {
    ar[root_b] = root_a;
    size[root_a] += size[root_b];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  long long int a[n], b[m];
  for (long long int x = 0; x < n; x++) {
    cin >> a[x];
  }
  for (long long int x = 0; x < m; x++) {
    cin >> b[x];
  }
  if (k >= n || k >= m) {
    cout << -1;
  } else {
    long long int time = -1;
    for (long long int x = 0; x < n; x++) {
      long long int r = a[x] + ta;
      long long int min = 0;
      long long int max = m - 1;
      while (min <= max) {
        long long int mid = min + (max - min) / 2;
        if (b[mid] < r) {
          min = mid + 1;
        } else {
          max = mid - 1;
        }
      }
      if (min + k - x < m) {
        if (b[min + k - x] > time) {
          time = b[min + k - x];
        }
      } else {
        time = -1;
        break;
      }
    }
    if (time != -1) {
      cout << time + tb;
    } else {
      cout << -1;
    }
  }
}
