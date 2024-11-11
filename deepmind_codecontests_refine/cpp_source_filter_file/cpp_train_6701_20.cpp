#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
#pragma comment(linker, "/STACK:256000000")
int main() {
  int n, k;
  cin >> n >> k;
  int t = -1;
  int p = -1;
  int *a = new int[n];
  int *s = new int[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", s + i);
  }
  int *b = new int[n];
  int *r = new int[n];
  for (int i = 0; i < n; i++) b[i] = i + 1;
  bool e = true;
  for (int j = 0; j < n; j++) {
    if (s[j] != b[j]) {
      e = false;
      break;
    }
  }
  if (e) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      r[a[j] - 1] = b[j];
    }
    swap(b, r);
    bool e = true;
    for (int j = 0; j < n; j++) {
      if (s[j] != b[j]) {
        e = false;
        break;
      }
    }
    if (e) {
      t = i + 1;
      break;
    }
  }
  bool z = false;
  if (t == 1) {
    z = true;
  }
  if (t % 2 == k % 2 && t > 0 && !z) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) b[i] = i + 1;
  for (int i = 0; i < n; i++) {
    r[a[i] - 1] = i + 1;
  }
  swap(a, r);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      r[a[j] - 1] = b[j];
    }
    swap(b, s);
    bool e = true;
    for (int j = 0; j < n; j++) {
      if (s[j] != b[j]) {
        e = false;
        break;
      }
    }
    if (e) {
      p = i + 1;
      break;
    }
  }
  if (t == 1 && p == 1 && k > 1) {
    cout << "NO\n";
    return 0;
  } else {
    if (t == 1 && k % 2 == 1) {
      {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  if (p % 2 == k % 2 && p > 0) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
