#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 10;
long long int hsh[N];
long long int binarySearch(long long int *arr, long long int n,
                           long long int target) {
  long long int lo = 0, hi = n - 1;
  while (lo <= hi) {
    long long int m = (lo + (hi - lo) / 2);
    if (arr[m] == target) {
      return m;
    } else if (arr[m] > target) {
      hi = m - 1;
    } else {
      lo = m + 1;
    }
  }
  return -1;
}
long long int fact(long long int x) {
  if (x == 1 || x == 0) return 1;
  return (x * (fact(x - 1)));
}
void sieve(long long int *arr, long long int n) {
  arr[0] = 1, arr[1] = 1;
  for (long long int i = 2; i * i <= n; i++) {
    if (arr[i] == 1) {
      for (long long int j = i * i; j <= n; j += i) {
        arr[j] = 1;
      }
    }
  }
}
long long int gcd(long long int l, long long int b) {
  if (l == b) return l;
  if (l > b)
    return gcd(l - b, b);
  else
    return gcd(l, b - l);
}
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int getposi(vector<long long int> ar, long long int e) {
  auto it = find(ar.begin(), ar.end(), e);
  if (it != ar.end()) {
    return (it - ar.begin());
  } else
    return -1;
}
int bs(string arr[], string x, long long int n) {
  long long int l = 0;
  long long int r = n - 1;
  while (l <= r) {
    long long int m = l + (r - l) / 2;
    long long int res;
    if (x == (arr[m])) res = 0;
    if (res == 0) return m;
    if (x > (arr[m]))
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
long long int match(string s1, string s2) {
  long long int j = 0;
  long long int flag = 0;
  for (long long int i = 0; i < s1.length(); i++) {
    if (s1[i] == s2[j]) {
      j++;
    } else
      j = j;
    if (j == s2.length()) {
      flag = 1;
      break;
    }
  }
  return flag;
}
string getbinary(long long int n) {
  string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}
int main(int argc, char const *argv[]) {
  clock_t begin = clock();
  file_i_o();
  long long int l, r;
  cin >> l >> r;
  if (l == r or l + 1 == r)
    cout << -1;
  else if (l % 2 == 0)
    cout << l << " " << l + 1 << " " << l + 2;
  else if (r - (l - 1) > 3)
    cout << l + 1 << " " << l + 2 << " " << l + 3;
  else
    cout << -1;
  return 0;
}
