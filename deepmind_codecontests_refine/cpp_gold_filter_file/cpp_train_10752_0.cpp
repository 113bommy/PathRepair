#include <bits/stdc++.h>
using namespace std;
unsigned long long int fact[(1 << 21)];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, 1, -1, -1, 1, 1, -1};
unsigned long long int power(unsigned long long int a, long long int b,
                             long long int mod) {
  unsigned long long int ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      ans = ((ans % mod) * (a % mod)) % mod;
    }
    a = ((a % mod) * (a % mod)) % mod;
    b = b / 2;
  }
  return ans;
}
unsigned long long int MMI(unsigned long long int n, long long int p) {
  return power(n, p - 2, p);
}
unsigned long long int ncr(unsigned long long int n, long long int r,
                           long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fact[n] * MMI(fact[r], p) % p * MMI(fact[n - r], p) % p) % p;
}
vector<long long int> makesieve(long long int n) {
  bool* isPrime = new bool[n + 1];
  for (int i = 0; i <= n; i++) {
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (long long int i = 2; i * i <= n; i++) {
    if (isPrime[i] == true) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  vector<long long int> ans;
  int j = 0;
  for (int i = 0; i <= n; i++)
    if (isPrime[i]) {
      ans.push_back(i);
    }
  return ans;
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int maxSubArraySum(long long int* a, long long int size) {
  long long int local_max = a[0];
  long long int global_max = a[0];
  long long int sum_so_far = a[0];
  long long int start = 0, end = 0;
  long long int tmp_start = 0;
  for (int i = 1; i < size; i++) {
    sum_so_far = a[i] + local_max;
    if (sum_so_far > a[i]) {
      local_max = sum_so_far;
    } else {
      tmp_start = i;
      local_max = a[i];
    }
    if (global_max < local_max) {
      global_max = local_max;
      start = tmp_start;
      end = i;
    }
  }
  return global_max;
}
long long int modulus_of_large_num(string num, long long int a) {
  long long int result = 0;
  for (long long int i = 0; i < num.length(); i++)
    result = (result * 10 + (long long int)num[i] - '0') % a;
  return result;
}
long long int NCR(long long int n, long long int k) {
  long long int ans = 1;
  k = k > n - k ? n - k : k;
  long long int j = 1;
  for (; j <= k; j++, n--) {
    if (n % j == 0) {
      ans *= n / j;
    } else if (ans % j == 0) {
      ans = ans / j * n;
    } else {
      ans = (ans * n) / j;
    }
  }
  return ans;
}
vector<int> factors(int n) {
  vector<int> first;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      first.push_back(i);
      n /= i;
    }
  }
  if (n > 1) first.push_back(n);
  return first;
}
int testcase = 0;
const long long int inf = 1e18;
const int N = 5e5 + 5;
int helper(int arr[], int n) {
  int prefix[n];
  int maxi = 0;
  unordered_map<int, int> umap;
  for (int i = 0; i < n; i++) {
    if (i == 0)
      prefix[i] = arr[i];
    else
      prefix[i] = arr[i] + prefix[i - 1];
    if (prefix[i] == 0) {
      maxi = max(maxi, i + 1);
      continue;
    }
    if (umap[prefix[i]]) {
      maxi = max(i - umap[prefix[i]] + 1, maxi);
    } else {
      umap[prefix[i]] = i + 1;
    }
  }
  return maxi;
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  set<int> second;
  int num;
  int occr = 0;
  unordered_map<int, int> umap;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    second.insert(arr[i]);
    umap[arr[i]]++;
    if (umap[arr[i]] > occr) {
      occr = umap[arr[i]];
      num = arr[i];
    }
  }
  int maxi = 0;
  for (auto x : second) {
    if (x == num) continue;
    int temp[n];
    for (int k = 0; k < n; k++) {
      if (arr[k] == num)
        temp[k] = 1;
      else if (arr[k] == x)
        temp[k] = -1;
      else
        temp[k] = 0;
    }
    maxi = max(helper(temp, n), maxi);
  }
  cout << maxi << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) {
    testcase++;
    solve();
  }
}
