#include <bits/stdc++.h>
using namespace std;
int n, a[300009], b[300009], pos[300009];
void mergesort(int l, int r) {
  if (r - l + 1 < 2) return;
  if (r - l + 1 == 2) {
    if (a[l] > a[r]) swap(a[r], a[l]);
    return;
  } else {
    int mid = (l + r) / 2, start1 = l, start2 = mid + 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    int ll = 0, *p = NULL;
    p = new int[r - l + 1];
    while (start1 <= mid && start2 <= r) {
      if (a[start1] < a[start2]) {
        p[ll] = a[start1];
        start1++;
      } else {
        p[ll] = a[start2];
        start2++;
      }
      ll++;
    }
    while (start1 <= mid) {
      p[ll] = a[start1];
      start1++;
      ll++;
    }
    while (start2 <= r) {
      p[ll] = a[start2];
      start2++;
      ll++;
    }
    for (int i = 0; i < ll; i++) {
      a[l + i] = p[i];
    }
    free(p);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      c1++;
      b[c1] = u;
      pos[b[c1]] = i;
    } else {
      c2++;
      a[c2] = u;
      pos[a[c2]] = i;
    }
  }
  if (c2 > c1) {
    mergesort(1, c2);
    cout << c2 << "\n";
    for (int i = c2; i >= 1; i--) {
      cout << pos[a[i]] << " ";
    }
  } else {
    for (int i = 1; i <= c1; i++) a[i] = b[i];
    cout << c1 << "\n";
    mergesort(1, c1);
    for (int i = 1; i <= c1; i++) {
      cout << pos[a[i]] << " ";
    }
  }
  return 0;
}
