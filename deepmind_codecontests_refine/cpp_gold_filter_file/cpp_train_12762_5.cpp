#include <bits/stdc++.h>
using namespace std;
bool flag[200000];
void quicksort(long long a[], int b[], int type[], int left, int right) {
  long long piv = a[(left + right) / 2];
  int i = left;
  int j = right;
  while (i <= j) {
    while (a[i] < piv) ++i;
    while (a[j] > piv) --j;
    if (i <= j) {
      swap(a[i], a[j]);
      swap(b[i], b[j]);
      swap(type[i], type[j]);
      ++i;
      --j;
    }
  }
  if (left < j) quicksort(a, b, type, left, j);
  if (i < right) quicksort(a, b, type, i, right);
}
int main() {
  unsigned int n;
  cin >> n;
  int a[n], b[n];
  long long p[n];
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  quicksort(p, a, b, 0, n - 1);
  vector<int> c1, c2, c3;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) c1.push_back(i);
    if (a[i] == 2) c2.push_back(i);
    if (a[i] == 3) c3.push_back(i);
    if (b[i] == 1 && a[i] != 1) c1.push_back(i);
    if (b[i] == 2 && a[i] != 2) c2.push_back(i);
    if (b[i] == 3 && a[i] != 3) c3.push_back(i);
  }
  int m;
  cin >> m;
  int k1 = 0, k2 = 0, k3 = 0;
  queue<int> q;
  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    q.push(c);
  }
  for (int i = 0; i < m; ++i) {
    int c = q.front();
    q.pop();
    if (c == 1) {
      if (k1 < c1.size())
        while (flag[c1[k1]]) {
          k1++;
          if (k1 == c1.size()) break;
        }
      if (k1 >= c1.size()) {
        cout << -1 << " ";
      } else {
        flag[c1[k1]] = true;
        cout << p[c1[k1]] << " ";
        k1++;
      }
    }
    if (c == 2) {
      if (k2 < c2.size())
        while (flag[c2[k2]]) {
          k2++;
          if (k2 == c2.size()) break;
        }
      if (k2 >= c2.size()) {
        cout << -1 << " ";
      } else {
        flag[c2[k2]] = true;
        cout << p[c2[k2]] << " ";
        k2++;
      }
    }
    if (c == 3) {
      if (k3 < c3.size())
        while (flag[c3[k3]]) {
          k3++;
          if (k3 == c3.size()) break;
        }
      if (k3 >= c3.size()) {
        cout << -1 << " ";
      } else {
        flag[c3[k3]] = true;
        cout << p[c3[k3]] << " ";
        k3++;
      }
    }
  }
  return 0;
}
