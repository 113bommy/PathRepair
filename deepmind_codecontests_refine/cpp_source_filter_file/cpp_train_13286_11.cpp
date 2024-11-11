#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return (res * res) * a;
  else
    return (res * res);
}
int mpow(int base, int exp, int mod) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result % mod;
}
int binarysearch(vector<pair<int, int>>& vec, int key) {
  int mid, best = -1;
  int l = 0, r = vec.size() - 1;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (vec[mid].first <= key) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return best;
}
int lowsearch(int a[], int q, int l, int r) {
  int ans = 0;
  int mid = (l + r) / 2;
  while (r >= l) {
    if (a[mid] >= q) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
      ans = mid + 1;
    }
  }
  return ans + 1;
}
int upsearch(int a[], int q, int l, int r) {
  int ans = 0;
  int mid = (l + r) / 2;
  while (r >= l) {
    if (a[mid] <= q) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
      ans = mid + 1;
    }
  }
  return ans + 1;
}
long long nprimes(long long n) {
  vector<char> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  long long cnt = 0;
  for (int i = 0; i < n + 1; i++) {
    if (is_prime[i] == true) {
      cnt++;
    }
  }
  return cnt;
}
int countDivisors(int n) {
  int cnt = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
vector<long long> trial_division1(long long n) {
  vector<long long> factorization;
  if (n == 1) {
    factorization.push_back(1);
  }
  for (long long d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      factorization.push_back(d);
      while (n % d == 0) {
        n /= d;
      }
    }
  }
  if (n > 1) factorization.push_back(n);
  return factorization;
}
int phi(int n) {
  float result = n;
  for (int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      result *= (1.0 - (1.0 / (float)p));
    }
  }
  if (n > 1) result *= (1.0 - (1.0 / (float)n));
  return (int)result;
}
bool palindrome(const string& s) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
vector<int> adj[1000004];
int d[100003];
bool visited[100003];
void visit(int vertex) {
  d[vertex] = 0;
  visited[vertex] = 1;
  for (int child : adj[vertex]) {
    if (!visited[child]) {
      visit(child);
    }
    d[vertex] = max(d[vertex], 1 + d[child]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << 1 << endl;
    }
    if (k == 3) {
      cout << 1 + (n * (n - 1) / 2) + 2 * (n * (n - 1) * (n - 2)) / 6 << endl;
    }
    if (k == 2) {
      cout << 1 + (n * (n - 1) / 2) << endl;
    }
    if (k == 4) {
      cout << 1 + (n * (n - 1) / 2) + (2 * (n * (n - 1) * (n - 2)) / 6) +
                  (9 * (n) * (n - 1) * (n - 2) * (n - 3)) / 24
           << endl;
    }
  }
}
