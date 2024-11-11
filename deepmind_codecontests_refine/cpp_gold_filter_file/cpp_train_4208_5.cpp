#include <bits/stdc++.h>
using namespace std;
const long long dx[] = {-1, 0, 1, 0};
const long long dy[] = {0, 1, 0, -1};
void SieveOfErat() {
  bool prime[1000001];
  memset(prime, true, sizeof(prime));
  for (long long vec = 2; vec * vec <= 1000000; vec++) {
    if (prime[vec] == true) {
      for (long long dd = vec * 2; dd <= 1000000; dd += vec) prime[dd] = false;
    }
  }
}
long long gcd(long long aa, long long id2) {
  if (aa == 0) {
    return id2;
  } else
    return gcd(aa % id2, id2);
}
struct vect {
  struct vect *foll;
  long long calc;
  struct vect *succ;
};
long long arr[500005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long vals, b;
  cin >> vals >> b;
  sort(arr, arr + n);
  n = unique(arr, arr + n) - arr;
  while (vals != b) {
    long long nxt = vals - 1;
    for (long long i = 0; i < n; i++) {
      long long tmp = vals - vals % arr[i];
      if (tmp < b)
        arr[i--] = arr[--n];
      else
        nxt = min(nxt, tmp);
    }
    vals = nxt;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
