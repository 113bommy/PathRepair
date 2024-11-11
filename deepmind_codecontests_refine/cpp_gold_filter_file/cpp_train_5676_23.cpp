#include <bits/stdc++.h>
using namespace std;
int n;
long long cma, cmi, A, m;
pair<long long, int> arr[100009];
long long haz[100009];
long long ansarr[100009];
long long ans = 0;
int main() {
  cin >> n >> A >> cma >> cmi >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i].first), haz[i] = arr[i].first;
    arr[i].second = i;
  }
  sort(arr + 1, arr + 1 + n);
  sort(haz + 1, haz + 1 + n);
  haz[n + 1] = A;
  int r = n + 1;
  long long valr = 0;
  for (int i = n; i >= 1; i--) {
    if (abs(A - arr[i].first) + valr > m) break;
    valr += abs(A - arr[i].first);
    r = i;
    haz[i] = A;
  }
  int l = 1;
  long long vall = 0;
  int mi = haz[1];
  int ll = 0;
  int rr = n + 1;
  int mm = 0;
  while (r <= n + 1) {
    while (l < r) {
      long long val = (haz[l + 1] - mi) * l;
      if (val + vall + valr <= m) {
        vall += val;
        l++;
        mi = haz[l];
      } else {
        mi += (m - valr - vall) / l;
        vall += ((m - valr - vall) / l) * l;
        break;
      }
    }
    long long va = mi * cmi + (n - r + 1) * cma;
    if (va > ans) {
      ans = va;
      mm = mi;
      ll = l;
      rr = r;
    }
    haz[r] = arr[r].first;
    valr -= A - arr[r].first;
    r++;
  }
  cout << ans << endl;
  if (l == r) l--;
  for (int i = 1; i <= ll; i++) ansarr[arr[i].second] = mm;
  for (int i = ll + 1; i < rr; i++) ansarr[arr[i].second] = arr[i].first;
  for (int i = rr; i <= n; i++) ansarr[arr[i].second] = A;
  for (int i = 1; i <= n; i++) cout << ansarr[i] << " ";
  return 0;
}
