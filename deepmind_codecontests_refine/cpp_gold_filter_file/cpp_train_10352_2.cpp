#include <bits/stdc++.h>
using namespace std;
template <typename typ>
void vout(vector<typ>& v) {
  for (int vint = 0; vint < (int)(v).size(); vint++) {
    cout << (v)[vint];
    if (vint == (int)(v).size() - 1)
      cout << endl;
    else
      cout << ' ';
  }
}
template <typename typ>
void arrout(typ* arr, int l) {
  for (int i = 0; i < l; i++) {
    cout << arr[i];
    if (i < l - 1)
      cout << ' ';
    else
      cout << endl;
  }
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
long long calc(int* A, int* B, int n) {
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    a[i] = A[i];
    b[i] = B[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  int idx = 0;
  while (idx < n && a[idx] <= b[0]) {
    idx++;
  }
  long long ans = 0;
  int j = 0;
  for (int i = idx; i < n; i++) {
    while (j < n && b[j] < a[i]) {
      j++;
    }
    j--;
    ans += j + 1;
  }
  return ans;
}
int main() {
  int n, m;
  int a[1 << 20];
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  long long iVersions[21], oVersions[21];
  iVersions[0] = oVersions[0] = 0;
  for (int i = 1; i <= n; i++) {
    iVersions[i] = iVersions[i - 1];
    oVersions[i] = oVersions[i - 1];
    int len = (1 << (i - 1));
    for (int j = 0; j < (1 << n); j += 2 * len) {
      iVersions[i] += calc(a + j, a + j + len, len);
      oVersions[i] += calc(a + j + len, a + j, len);
    }
  }
  std::ios_base::sync_with_stdio(false);
  int q;
  for (int i = 0; i < m; i++) {
    scanf("%d", &q);
    swap(iVersions[q], oVersions[q]);
    long long diff = iVersions[q] - oVersions[q];
    for (int j = 0; j < q; j++) {
      swap(iVersions[j], oVersions[j]);
    }
    for (int j = q + 1; j <= n; j++) {
      iVersions[j] += diff;
      oVersions[j] -= diff;
    }
    cout << (iVersions[n]) << endl;
  }
}
