#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int p[n], c[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> c[i];
  }
  for (int j = 0; j < n - 1; j++) {
    int mini = j;
    for (int i = j + 1; i < n; i++) {
      if (c[i] < c[mini]) {
        mini = i;
      }
    }
    if (mini != j) {
      swap(c[j], c[mini]);
      swap(p[j], p[mini]);
    }
  }
  reverse(p, p + n);
  reverse(c, c + n);
  int cnt = 1, idx = 0, points = 0;
  while (idx < n && cnt > 0) {
    if (c[idx] == 0) {
      break;
    }
    points += p[idx];
    cnt += c[idx];
    cnt--;
    idx++;
  }
  if (idx) {
    for (int j = idx; j < n - 1; j++) {
      int maxi = j;
      for (int i = j + 1; i < n; i++) {
        if (p[i] > p[maxi]) {
          maxi = i;
        }
      }
      if (maxi != j) {
        swap(c[j], c[maxi]);
        swap(p[j], p[maxi]);
      }
    }
  }
  for (int i = idx; i < n; i++) {
    if (cnt < 1) {
      break;
    }
    points += p[i];
    cnt--;
  }
  cout << points;
}
