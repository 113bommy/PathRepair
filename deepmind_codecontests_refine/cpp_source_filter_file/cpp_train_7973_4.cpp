#include <bits/stdc++.h>
using namespace std;
long long binarySearchE(long long minimum, long long maximum, long long prevAns,
                        long long n, long long t);
long long binarySearchT(long long minimum, long long maximum, long long prevAns,
                        long long n);
long long solve(long long n);
long long findE(long long t, long long n);
int main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int q;
  cin >> q;
  vector<long long> arr;
  for (int i = 0; i < q; i++) {
    long long temp;
    cin >> temp;
    arr.push_back(temp);
  }
  for (int i = 0; i < arr.size(); i++) {
    cout << solve(arr[i]) << endl;
  }
  return 0;
}
long long solve(long long n) { return binarySearchT(0, n, 0, n) + n - 1; }
long long binarySearchT(long long minimum, long long maximum, long long prevAns,
                        long long n) {
  if (minimum <= maximum) {
    long long t = (maximum + minimum) / 2;
    long long w = findE(t, n);
    if (w != -1) {
      prevAns = w;
      return binarySearchT(t + 1, maximum, prevAns, n);
    }
    return binarySearchT(minimum, t - 1, prevAns, n);
  } else {
    return prevAns;
  }
}
long long findE(long long t, long long n) {
  long long e = (n - t - 2) / 2;
  long long t1 = (t * (t + 1)) / 2;
  long long t2 = (t * (t - 1)) / 2;
  if (e >= t1) {
    return t1;
  } else if (e <= t2) {
    return -1;
  } else {
    return e;
  }
}
long long binarySearchE(long long minimum, long long maximum, long long prevAns,
                        long long n, long long t) {
  if (minimum <= maximum) {
    long long e = (minimum + maximum) / 2;
    if (n - t - 2 >= ceil((double)(e + n - 1) / 2)) {
      prevAns = e;
      return binarySearchE(e + 1, maximum, prevAns, n, t);
    }
    return binarySearchE(minimum, e - 1, prevAns, n, t);
  } else {
    return prevAns;
  }
}
