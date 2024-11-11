#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void relaxmax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}
struct HeapTracksSumToKth {
  int K;
  long long sum;
  multiset<pair<int, int> > elements;
  multiset<pair<int, int> >::iterator kpos;
  HeapTracksSumToKth(int K) : K(K), sum(0), elements(), kpos(elements.end()) {}
  void add(pair<int, int> x) {
    if (K == 0) {
      return;
    }
    if ((int)elements.size() >= K) {
      if (x < *kpos) {
        sum -= kpos->first;
        sum += x.first;
        elements.insert(x);
        --kpos;
      } else {
        elements.insert(x);
      }
    } else {
      elements.insert(x);
      sum += x.first;
    }
    fix_kpos();
  }
  void fix_kpos() {
    if ((int)elements.size() <= K) {
      kpos = elements.end();
      --kpos;
    }
  }
  void remove(pair<int, int> x) {
    if (K == 0) {
      return;
    }
    if (x <= *kpos) {
      ++kpos;
      sum -= x.first;
      if (kpos != elements.end()) {
        sum += kpos->first;
      }
    }
    elements.erase(elements.find(x));
  }
};
long long solve(const vector<int> &arr, int len, int k) {
  HeapTracksSumToKth heap(k);
  for (int i = 0; i <= k; ++i) {
    heap.add(make_pair(0, -100 - i));
  }
  long long sum = 0, res = -LONG_LONG_MAX / 4;
  for (int i = 0; i < len - 1; ++i) {
    heap.add(make_pair(arr[i], i));
    sum += arr[i];
  }
  int n = (int)arr.size();
  for (int i = len - 1; i < n; ++i) {
    heap.add(make_pair(arr[i], i));
    sum += arr[i];
    long long segment = sum - 2 * heap.sum;
    relaxmax(res, abs(segment));
    heap.remove(make_pair(arr[i - len + 1], i - len + 1));
    sum -= arr[i - len + 1];
  }
  return res;
}
int main() {
  cin.sync_with_stdio(0);
  int n, len;
  cin >> n >> len;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  long long result = solve(arr, len, k);
  for (typeof((arr).begin()) it = (arr).begin(); it != (arr).end(); ++it) {
    *it = -*it;
  }
  relaxmax(result, solve(arr, len, k));
  cout << result << '\n';
  return 0;
}
