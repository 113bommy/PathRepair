#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long, vector<long long>, greater<long long>>
    minHeap;
long long INF = 1e17;
const int N = 5e5 + 33;
const long long MD = 1000000007;
inline long long mul(long long a, long long b) { return (a * b) % MD; }
inline long long po(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b /= 2;
  }
  return ans;
}
long long n, m, t, k;
long long arr[N];
string s;
pair<int, int> x, y;
int binarysearch1(int l, int r, int x) {
  if (l == r) {
    return l;
  }
  int mid = (l + r) >> 1;
  cout << "? " << l << " " << x << " " << mid << " " << x << endl;
  int res;
  cin >> res;
  if (res & 1) {
    return binarysearch1(l, mid, x);
  } else {
    return binarysearch1(mid + 1, r, x);
  }
}
int binarysearch2(int l, int r, int x) {
  if (l == r) {
    return l;
  }
  int mid = (l + r) >> 1;
  cout << "? " << x << " " << l << " " << x << " " << mid << endl;
  int res;
  cin >> res;
  if (res & 1) {
    return binarysearch1(l, mid, x);
  } else {
    return binarysearch1(mid + 1, r, x);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "? " << i << " 1 " << i << " " << n << endl;
    int res;
    cin >> res;
    if (x.first == 0 && (res & 1))
      x.first = i;
    else if (x.first != 0 && (res & 1)) {
      x.second = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << "? 1 " << i << " " << n << " " << i << endl;
    int res;
    cin >> res;
    if (y.first == 0 && (res & 1))
      y.first = i;
    else if (y.first != 0 && (res & 1)) {
      y.second = i;
      break;
    }
  }
  if (x.first == 0) {
    int h = binarysearch1(1, n, y.first);
    cout << "! " << h << " " << y.first << " " << h << " " << y.second << endl;
  } else if (y.first == 0) {
    int h = binarysearch2(1, n, x.first);
    cout << "! " << x.first << " " << h << " " << x.second << " " << h << endl;
  } else {
    cout << "? " << x.first << " " << y.first << " " << x.first << " "
         << y.first << endl;
    int res;
    cin >> res;
    if (res == 1) {
      cout << "! " << x.first << " " << y.first << " " << x.second << " "
           << y.second << endl;
    } else {
      cout << "! " << x.first << " " << y.second << " " << x.second << " "
           << y.first << endl;
    }
  }
  return 0;
}
