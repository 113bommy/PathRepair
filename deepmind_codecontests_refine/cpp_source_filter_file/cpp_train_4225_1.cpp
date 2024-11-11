#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1ll;
  while (b > 0) {
    if (b % 2 != 0) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res % 1000000007;
}
long long ncr(long long n, long long k) {
  if (k > n - k) k = n - k;
  long long pro = 1;
  for (long long i = 0; i < k; i++) {
    pro = (pro * (n - i)) % 1000000007;
    pro /= (i + 1);
  }
  return (pro) % 1000000007;
}
void swap(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}
vector<long long> prime;
void seive() {
  vector<bool> isprime(1000001, true);
  for (int i = 2; i * i <= 1000000; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= 1000000; j += i) {
        isprime[j] = false;
      }
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isprime[i]) prime.push_back(i);
  }
}
vector<long long> parent;
long long find(long long p) {
  if (parent[p] == p) return parent[p];
  return parent[p] = find(parent[p]);
}
void unun(long long a, long long b) {
  long long r1 = find(a);
  long long r2 = find(b);
  if (r1 != r2) parent[r2] = r1;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> arr(n);
  set<long long, greater<long long>> s;
  long long odd = (m / 2), even = (m / 2);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    s.insert(arr[i]);
  }
  long long x = 0, y = 0;
  for (auto itr : s) {
    if (itr > m) {
      if (itr % 2 == 0) {
        even++;
      } else {
        odd++;
      }
    }
    if (itr % 2 == 0)
      x++;
    else
      y++;
  }
  if (even < (n / 2)) {
    cout << "-1";
    return;
  }
  if (odd < (n / 2)) {
    cout << "-1";
    return;
  }
  set<long long> eno, ono;
  x = 0;
  for (auto itr : s) {
    if (itr % 2 == 0) {
      eno.insert(itr);
      x++;
      if (x == (n / 2)) break;
    }
  }
  y = 0;
  for (auto itr : s) {
    if (itr % 2 != 0) {
      ono.insert(itr);
      y++;
      if (y == n / 2) break;
    }
  }
  long long cnt = 0;
  for (int i = 2; i < 2e6 && x < (n / 2); i += 2) {
    if (s.find(i) == s.end()) {
      x++;
      eno.insert(i);
      cnt++;
    }
  }
  for (int i = 1; i < 2e6 && y < (n / 2); i += 2) {
    if (s.find(i) == s.end()) {
      y++;
      ono.insert(i);
      cnt++;
    }
  }
  cout << cnt << "\n";
  vector<long long> ans(n, -1);
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      if (eno.find(arr[i]) != eno.end()) {
        ans[i] = arr[i];
        eno.erase(arr[i]);
      }
    } else {
      if (ono.find(arr[i]) != ono.end()) {
        ans[i] = arr[i];
        ono.erase(arr[i]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      if (!eno.empty()) {
        auto itr = eno.begin();
        ans[i] = *itr;
        eno.erase(itr);
      } else if (!ono.empty()) {
        auto itr = ono.begin();
        ans[i] = *itr;
        ono.erase(itr);
      }
    }
  }
  for (auto itr : ans) cout << itr << " ";
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
