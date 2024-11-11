#include <bits/stdc++.h>
using namespace std;
long long const N = 1e9 + 6010;
int n, q;
long long k, mx = 1000000000000000000;
long long num[30];
stringstream ss;
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long calc(long long m, int index) {
  long long ans;
  if (index) {
    ans = ((m * (m + (long long)1)) / 2);
    int i = 2;
    while (m - num[i] > 0 && i < 20) {
      long long add = m - num[i];
      ans += ((add * (add + (long long)1)) / 2);
      i++;
      if (ans > mx) return (mx + (long long)2);
    }
  } else {
    ans = m;
    int i = 2;
    while (m - num[i] > 0 && i < 20) {
      long long add = m - num[i];
      ans += add;
      i++;
    }
  }
  return ans;
}
long long binarysearch(int index, long long second, long long e) {
  long long val = 0;
  while (second < e) {
    long long mid = second + (e - second) / (long long)2, ans, ans2, ans3;
    long long mid2 = mid + (long long)1;
    long long mid3 = mid - (long long)1;
    ans = calc(mid, index);
    ans2 = calc(mid2, index);
    ans3 = calc(mid3, index);
    if (ans2 >= k && ans < k) {
      e = mid + (long long)1;
      val = ans;
      break;
    }
    if (ans >= k && ans3 < k) {
      e = mid;
      val = ans3;
      break;
    } else if (ans2 < k)
      second = mid + (long long)1;
    else if (ans3 > k)
      e = mid - (long long)1;
    else
      e = mid;
  }
  k -= val;
  return e;
}
int main() {
  long long d = 9;
  for (int i = 2; i < 20; ++i) {
    num[i] = d;
    d = (long long)(d * 10) + (long long)(9);
  }
  cin >> q;
  while (q--) {
    cin >> k;
    long long e = binarysearch(1, 1, N);
    e = binarysearch(0, 1, min(e, k));
    string finally;
    ss << e;
    ss >> finally;
    cout << finally[k - 1] << endl;
    ss.clear();
  }
}
