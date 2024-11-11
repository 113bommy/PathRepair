#include <bits/stdc++.h>
using namespace std;
int n, q;
int nn;
int *arra, *arrw;
long long int *suml, *sumr, *sum;
long long int mod = 1E9 + 7;
int mx;
long sm;
bool TEST = 0;
void read() {
  cin >> n >> q;
  nn = ceil(log2(n)) * n - 1;
  if (nn < 5) nn = 5;
  arra = new int[n];
  arrw = new int[n];
  suml = new long long int[nn];
  sumr = new long long int[nn];
  sum = new long long int[nn];
  sm = 0;
  for (int i = 0; i < n; i++) {
    cin >> arra[i];
    arra[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> arrw[i];
    sm += arrw[i];
  }
  mx = arra[n - 1];
}
long long int getValLeft(int ind) {
  long long int w = arrw[ind];
  w *= arra[ind] - ((long long int)ind);
  w %= mod;
  return w;
}
long long int getVal(int ind) { return arrw[ind]; }
long long int getValRight(int ind) {
  long long int w = arrw[ind];
  w *= ((long long int)mx) - ((long long int)arra[ind]) -
       ((long long int)(n - ind - 1));
  w %= mod;
  return w;
}
long long int buildSeg(long long int *arr, long long int (*val)(int), int s,
                       int e, int i, bool ismod = true) {
  if (s == e) {
    arr[i] = val(s);
    if (ismod) arr[i] %= mod;
    return arr[i];
  }
  int m = (s + e) / 2;
  arr[i] = (buildSeg(arr, val, s, m, i * 2 + 1, ismod) +
            buildSeg(arr, val, m + 1, e, i * 2 + 2, ismod));
  if (ismod) arr[i] %= mod;
  return arr[i];
}
long long int sumSeg(long long int *arr, int s, int e, int i, int rs, int re,
                     bool ismod = true) {
  if (s >= rs && e <= re) return arr[i];
  if (e < rs || s > re) return 0;
  int m = (s + e) / 2;
  long long int res = sumSeg(arr, s, m, i * 2 + 1, rs, re, ismod);
  res += sumSeg(arr, m + 1, e, i * 2 + 2, rs, re, ismod);
  if (ismod) res %= mod;
  return res;
}
void updateSeg(long long int *arr, int s, int e, int i, int ind,
               long long int diff, bool ismod = true) {
  if (ind < s || ind > e) return;
  arr[i] = (arr[i] + diff);
  if (ismod) arr[i] %= mod;
  if (s == e) return;
  int m = (s + e) / 2;
  updateSeg(arr, s, m, i * 2 + 1, ind, diff, ismod);
  updateSeg(arr, m + 1, e, i * 2 + 2, ind, diff, ismod);
}
int segIndex(long long int *arr, int s, int e, int i, long long int sml) {
  if (s == e) return s;
  int m = (s + e) / 2;
  if (arr[i * 2 + 1] > sml) return segIndex(arr, s, m, i * 2 + 1, sml);
  return segIndex(arr, m + 1, e, i * 2 + 2, sml - arr[i * 2 + 1]);
}
int getMedian(int s, int e) {
  long long int sml = sumSeg(sum, 0, n - 1, 0, s, e, false);
  long long int smlb = 0;
  if (s > 0) smlb = sumSeg(sum, 0, n - 1, 0, 0, s, false);
  int ind = segIndex(sum, 0, n - 1, 0, smlb + sml / 2);
  return ind;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  buildSeg(suml, getValLeft, 0, n - 1, 0);
  buildSeg(sumr, getValRight, 0, n - 1, 0);
  buildSeg(sum, getVal, 0, n - 1, 0, false);
  if (TEST) {
    cout << endl << "--------------" << endl;
    for (int i = 0; i < nn; i++) cout << sum[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << getVal(i) << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << getValLeft(i) << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << getValRight(i) << " ";
    cout << endl;
    cout << "--------------" << endl;
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    if (x < 0) {
      x = -x;
      x--;
      int vl = getValLeft(x);
      int vr = getValRight(x);
      int vm = getVal(x);
      arrw[x] = y;
      int nl = getValLeft(x);
      int nr = getValRight(x);
      int nm = y;
      int dl = ((nl - vl) + mod * 2) % mod;
      int dr = ((nr - vr) + mod * 2) % mod;
      int dm = nm - vm;
      updateSeg(suml, 0, n - 1, 0, x, dl);
      updateSeg(sumr, 0, n - 1, 0, x, dr);
      updateSeg(sum, 0, n - 1, 0, x, dm, false);
    } else {
      x--;
      y--;
      int med = getMedian(x, y);
      long long int need = 0;
      int pb, pa, tb, ta;
      pa = med + 1;
      pb = med;
      long long int smm = sumSeg(sum, 0, n - 1, 0, x, y, false);
      if (TEST) {
        cout << "-------------" << endl;
        cout << smm << " " << med << endl;
      }
      if (smm % 2) {
        pb--;
        tb = arra[med] - 1;
        ta = arra[med] + 1;
      } else {
        long long int sb = 0;
        if (med > x) sb = sumSeg(sum, 0, n - 1, 0, x, med - 1, false);
        if (sb == smm / 2) {
          pa = pb;
          pb = pb - 1;
          tb = (arra[pb] + arra[pa]) / 2;
          ta = tb + 1;
        } else {
          pb--;
          tb = arra[med] - 1;
          ta = arra[med] + 1;
        }
      }
      if (TEST) {
        cout << pb << " " << pa << endl;
        cout << tb << " " << ta << endl;
      }
      if (pb >= x) {
        if (TEST)
          cout << "L: " << (sumSeg(sumr, 0, n - 1, 0, x, pb) % mod) << " - "
               << (sumSeg(sum, 0, n - 1, 0, x, pb)) << " * "
               << (((mx - tb - (n - pb)) + 1) % mod) << endl;
        need = ((need + sumSeg(sumr, 0, n - 1, 0, x, pb) % mod -
                 (sumSeg(sum, 0, n - 1, 0, x, pb) *
                  (((mx - tb - (n - pb)) + 1) % mod)) %
                     mod) +
                mod) %
               mod;
      }
      if (pa <= y) {
        if (TEST)
          cout << "R: " << (sumSeg(suml, 0, n - 1, 0, pa, y) % mod) << " - "
               << (sumSeg(sum, 0, n - 1, 0, pa, y)) << " * " << (ta - pa)
               << endl;
        need = ((need + sumSeg(suml, 0, n - 1, 0, pa, y) % mod -
                 (sumSeg(sum, 0, n - 1, 0, pa, y) * (ta - pa)) % mod) +
                mod) %
               mod;
      }
      if (TEST) cout << "-------------" << endl;
      cout << need << endl;
    }
  }
  return 0;
}
