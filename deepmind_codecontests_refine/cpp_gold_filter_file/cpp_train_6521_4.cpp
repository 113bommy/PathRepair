#include <bits/stdc++.h>
using namespace std;
int arr[1200001];
int factor[1000001];
long long segtree[2400001];
bool done[2400001];
int n, q;
int segsize;
void add(int value, int left, int right, int idx, int pos) {
  if (left == right && left == idx) {
    segtree[pos] += value;
    return;
  }
  if (left > idx || right < idx || left == right) return;
  if (left <= idx && right >= idx) {
    segtree[pos] += value;
    int mid = left + right;
    mid /= 2;
    add(value, left, mid, idx, pos * 2 + 1);
    add(value, mid + 1, right, idx, pos * 2 + 2);
    return;
  }
}
void update(int val, int idx, int segL, int segR, int pos) {
  if (segL > idx || idx > segR) return;
  if (segL == segR) {
    if (segL == idx) segtree[pos] += val;
    if (segtree[pos] <= 2) done[pos] = true;
    return;
  }
  if (done[pos * 2 + 1] && done[pos * 2 + 2]) {
    done[pos] = true;
    return;
  }
  segtree[pos] += val;
  int mid = segL + segR;
  mid /= 2;
  update(val, idx, segL, mid, pos * 2 + 1);
  update(val, idx, mid + 1, segR, pos * 2 + 2);
}
long long getval(int L, int R, int segL, int segR, int pos) {
  if (max(L, segL) > min(R, segR)) return 0;
  if (L <= segL && segR <= R)
    return segtree[pos];
  else {
    int mid = segL + segR;
    mid /= 2;
    long long ans = getval(L, R, segL, mid, pos * 2 + 1) +
                    getval(L, R, mid + 1, segR, pos * 2 + 2);
    return ans;
  }
}
void getup(int L, int R, int segL, int segR, int pos) {
  if (done[pos]) return;
  if (done[pos * 2 + 1] && done[pos * 2 + 2]) {
    done[pos] = true;
    return;
  }
  if (max(L, segL) > min(R, segR)) return;
  if (L <= segL && segR <= R) {
    for (int i = segL; i <= segR; i++) {
      int value = arr[i];
      int minus = factor[arr[i]];
      arr[i] = factor[arr[i]];
      value -= minus;
      value *= -1;
      update(value, i, 0, n - 1, 0);
    }
    return;
  }
  if (segL == segR) return;
  int mid = segL + segR;
  mid /= 2;
  getup(L, R, segL, mid, pos * 2 + 1);
  getup(L, R, mid + 1, segR, pos * 2 + 2);
}
int main() {
  memset(factor, 0, sizeof factor);
  memset(done, false, sizeof done);
  memset(segtree, 0, sizeof segtree);
  memset(arr, 0, sizeof arr);
  for (int i = 1; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) {
      factor[j]++;
    }
  }
  cin >> n >> q;
  segsize = ceil(log2(n)) + 1;
  segsize = (1 << segsize) - 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    add(arr[i], 0, n - 1, i, 0);
  }
  for (int i = 0; i < q; i++) {
    int det, L, R;
    scanf("%d%d%d", &det, &L, &R);
    if (det == 1) {
      getup(L - 1, R - 1, 0, n - 1, 0);
    } else {
      long long ans = getval(L - 1, R - 1, 0, n - 1, 0);
      cout << ans << endl;
    }
  }
  return 0;
}
