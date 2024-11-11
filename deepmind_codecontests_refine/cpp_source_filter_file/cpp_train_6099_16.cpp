#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
long long power(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long t = power(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1) t = (t * a) % m;
  return t;
}
using namespace std;
long long n;
string st, gt;
bool predicate(long long mid, long long arr[]) {
  string temp;
  temp = st;
  for (long long i = 0; i <= mid; i++) {
    temp[arr[i] - 1] = '#';
  }
  long long len = 0;
  for (long long i = 0; i < n; i++) {
    if (temp[i] == gt[len]) {
      len++;
      if (len == gt.length()) return true;
    }
  }
  return false;
}
int main() {
  cin >> st >> gt;
  n = st.length();
  long long arr[st.length()];
  for (long long i = 0; i < st.length(); i++) cin >> arr[i];
  long long l = 0, h = n - 1;
  long long mid = l + (h - l) / 2 + 1;
  long long flag = 0, len = 0;
  string temp = st;
  temp[arr[0]] = '#';
  for (long long i = 0; i < n; i++) {
    if (temp[i] == gt[len]) {
      len++;
      if (len == gt.length()) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) {
    cout << "0";
    return 0;
  }
  while (l <= h) {
    if (l == h) {
      mid = h;
      break;
    }
    if (predicate(mid, arr)) {
      l = mid;
    } else {
      h = mid - 1;
    }
    mid = l + (h - l) / 2 + 1;
  }
  cout << mid + 1 << endl;
}
