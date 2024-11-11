#include <bits/stdc++.h>
using namespace std;
int kol, k;
int a[200100];
set<int> s;
void revMerge(int *a, int l, int r) {
  if (kol >= k) return;
  if (l + 1 == r) return;
  int mid = (l + r) / 2;
  int tmp = l + mid;
  vector<int> a1;
  vector<int> a2;
  a1.clear();
  a2.clear();
  for (int i = l; i < l + r - mid; i++) {
    a1.push_back(a[i]);
  }
  for (int i = l + r - mid; i < r; i++) {
    a2.push_back(a[i]);
  }
  int len1 = a1.size();
  int len2 = a2.size();
  for (int i = l; i < l + len2; i++) a[i] = a2[i - l];
  for (int i = l + len2; i < r; i++) a[i] = a1[i - len2 - l];
  kol += 2;
  a1.resize(0);
  a2.resize(0);
  revMerge(a, l, mid);
  revMerge(a, mid, r);
}
int main() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) a[i] = i + 1;
  if (k % 2 == 0)
    cout << "-1";
  else {
    kol++;
    revMerge(a, 0, n);
    if (kol > k) {
      cout << "-1";
    } else {
      for (int i = 0; i < n; i++) cout << a[i] << " ";
    }
  }
  return 0;
}
