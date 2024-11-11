#include <bits/stdc++.h>
using namespace std;
class seg_update_sum {
 public:
  vector<long long> arr;
  vector<bool> flag;
  int size;
  int n;
  seg_update_sum(int max) : size(max * 2), n(size / 2) {
    arr.resize(size);
    flag.resize(size);
    fill(flag.begin(), flag.end(), false);
  }
  void range_update(int left, int right, long long v) {
    left = max(left + n, n), right = min(right + n, size - 1);
    if (left > right) return;
    int le = left, ri = right;
    propagate(left);
    propagate(right);
    for (int k = 0; left <= right;
         k++, left = (left + 1) >> 1, right = (right - 1) >> 1) {
      if (left & 1) {
        arr[left] = (v << k);
        flag[left] = true;
      }
      if (!(right & 1)) {
        arr[right] = (v << k);
        flag[right] = true;
      }
    }
    popUp(le);
    popUp(ri);
  }
  void propagate(int i) {
    int k = 0;
    while (i >> k) k++;
    k--;
    for (; k >= 0; k--) {
      int j = i >> k;
      if (!flag[j]) continue;
      if (k > 0) {
        arr[2 * j] = arr[j] >> 1;
        flag[2 * j] = true;
        arr[2 * j + 1] = arr[j] >> 1;
        flag[2 * j + 1] = true;
      }
      flag[j] = false;
    }
  }
  void popUp(int i) {
    for (int k = 0; i > 1; k++, i /= 2) {
      if (!flag[i >> 1]) arr[i >> 1] = arr[i] + arr[i ^ 1];
    }
  }
  long long range_sum(int left, int right) {
    left = max(left + n, n), right = min(right + n, size - 1);
    if (left > right) return 0;
    propagate(left);
    propagate(right);
    long long res = 0;
    for (; left <= right; left = (left + 1) >> 1, right = (right - 1) >> 1) {
      if (left & 1) {
        res += arr[left];
      }
      if (!(right & 1)) {
        res += arr[right];
      }
    }
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> a(n), k(n - 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> k[i];
  vector<long long> b(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    b[i] = a[i] - sum;
    sum += k[i];
  }
  seg_update_sum seg(1 << 20);
  for (int i = 0; i < n; i++) {
    seg.range_update(i, i, b[i]);
  }
  vector<long long> rui(n);
  long long ssum = 0;
  sum = 0;
  for (int i = 0; i < n; i++) {
    rui[i] = ssum;
    sum += k[i];
    ssum += sum;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      int ind;
      long long v;
      cin >> ind >> v;
      ind--;
      long long cur = seg.range_sum(ind, ind);
      cur += v;
      int left = 0, right = n - 1;
      while (left < right) {
        int mid = (left + right + 1) / 2;
        long long target = seg.range_sum(mid, mid);
        if (target > cur) {
          right = mid - 1;
        } else {
          left = mid;
        }
      }
      seg.range_update(ind, left, cur);
    } else {
      int le, ri;
      cin >> le >> ri;
      le--, ri--;
      long long tori = seg.range_sum(le, ri);
      long long kei = rui[ri];
      if (le > 0) kei -= rui[le - 1];
      cout << tori + kei << "\n";
    }
  }
  return 0;
}
