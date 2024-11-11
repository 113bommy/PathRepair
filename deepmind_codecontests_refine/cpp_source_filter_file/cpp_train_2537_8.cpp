#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const int N = 1000005;
int n, k, a[N];
int main() {
  int sum = 0, mn = 1 << 30, idx;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] < mn) mn = a[i], idx = i;
  }
  if (k <= 0 || sum < k) {
    puts("No");
    return 0;
  }
  if (n == 1) {
    if (k == a[0]) {
      puts("Yes");
      for (int i = 1; i <= k * 2; i++) cout << 1 << " ";
    } else
      puts("No");
    return 0;
  }
  if (mn > k) {
    if (k == 1) {
      puts("No");
      return 0;
    }
    puts("Yes");
    cout << 1 << " ";
    for (int i = 1; i < a[2]; i++) {
      cout << 2 << " " << 2 << " ";
    }
    cout << 1 << " ";
    cout << 2 << " ";
    if (k == 2) {
      for (int i = 1; i < a[1]; i++) cout << "1 1 ";
      for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= a[i]; j++) cout << i << " " << i << " ";
      }
      cout << 2 << endl;
      return 0;
    }
    for (int i = 1; i <= a[1] - k + 1; i++) cout << "1 1 ";
    cout << 2 << " ";
    k -= 2;
    for (int i = 1; i < k; i++) cout << "1 1 ";
    cout << 1 << " ";
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j <= a[i]; j++) cout << i << " " << i << " ";
    }
    cout << 1 << endl;
    return 0;
  }
  puts("Yes");
  for (int i = 1; i < a[idx]; i++) {
    cout << idx << " " << idx << " ";
  }
  k -= a[idx];
  for (int i = 1; i <= n && k; i++) {
    if (i == idx) continue;
    for (int j = 1; j <= a[i] && k; j++) {
      cout << i << " " << i << " ";
      k--;
      a[i]--;
      j--;
    }
  }
  cout << idx << " ";
  for (int i = 1; i <= n; i++) {
    if (i == idx) continue;
    for (int j = 1; j <= a[i]; j++) {
      cout << i << " " << i << " ";
    }
  }
  cout << idx << endl;
  return 0;
}
