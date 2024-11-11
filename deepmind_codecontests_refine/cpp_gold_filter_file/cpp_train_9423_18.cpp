#include <bits/stdc++.h>
using namespace std;
int getMid(int s, int e) { return s + (e - s) / 2; }
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
  if (qs <= ss && qe >= se) return st[si];
  if (se < qs || ss > qe) return 0;
  int mid = getMid(ss, se);
  return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
         getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
  if (i < ss || i > se) return;
  st[si] = st[si] + diff;
  if (se != ss) {
    int mid = getMid(ss, se);
    updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
    updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
  }
}
void updateValue(int arr[], int *st, int n, int i, int diff) {
  if (i < 0 || i > n - 1) {
    return;
  }
  updateValueUtil(st, 0, n - 1, i, diff, 0);
}
int getSum(int *st, int n, int qs, int qe) {
  if (qs < 0 || qe > n - 1 || qs > qe) {
    return 0;
  }
  return getSumUtil(st, 0, n - 1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
  if (ss == se) {
    st[si] = arr[ss];
    return arr[ss];
  }
  int mid = getMid(ss, se);
  st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
           constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
  return st[si];
}
int *constructST(int arr[], int n) {
  int x = (int)(ceil(log2(n)));
  int max_size = 2 * (int)pow(2, x) - 1;
  int *st = new int[max_size];
  constructSTUtil(arr, 0, n - 1, st, 0);
  return st;
}
int main() {
  int n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  int arra[n + 1];
  int arrb[n + 1];
  for (int i = 0; i <= n; i++) {
    arra[i] = 0;
    arrb[i] = 0;
  }
  int *st1 = constructST(arra, n + 1);
  int *st2 = constructST(arrb, n + 1);
  for (int i = 1; i <= q; i++) {
    int inp;
    cin >> inp;
    if (inp == 1) {
      int i1, i2;
      cin >> i1 >> i2;
      int diffa = 0;
      int diffb = 0;
      if (i2 + arra[i1] > a) {
        diffa = a - arra[i1];
        arra[i1] = a;
        updateValue(arra, st1, n + 1, i1, diffa);
      } else {
        diffa = i2;
        arra[i1] += diffa;
        updateValue(arra, st1, n + 1, i1, diffa);
      }
      if (i2 + arrb[i1] > b) {
        diffb = b - arrb[i1];
        arrb[i1] = b;
        updateValue(arrb, st2, n + 1, i1, diffb);
      } else {
        diffb = i2;
        arrb[i1] += diffb;
        updateValue(arrb, st2, n + 1, i1, diffb);
      }
    } else {
      int i1;
      cin >> i1;
      cout << getSum(st1, n + 1, i1 + k, n) + getSum(st2, n + 1, 1, i1 - 1)
           << endl;
    }
  }
  return 0;
}
