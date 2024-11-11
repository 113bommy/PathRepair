#include <bits/stdc++.h>
using namespace std;
long long int greatestSubarraySum(long long int array[], long long int n);
long long int binarySearch(vector<long long> arr, long long int l,
                           long long int r, long long int x);
long long int modpower(long long int x, long long int y, long long int p);
long long int power(long long int x, long long int y);
long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b);
long long int search(long long int arr[], long long int n, long long int k);
string findSum(string str1, string str2);
long long int extendedGcd(long long int a, long long int b, long long int &x,
                          long long int &y);
bool find_any_solution(long long int a, long long int b, long long int c,
                       long long int &x0, long long int &y0, long long int &g);
long long int countSetBits(long long int n);
void primeFactors(long long int n, map<long long int, long long int> &arr2,
                  long long int k, long long int &flaggy);
void matrixMultiply(long long int a[3][3], long long int b[3][3]);
void matrixPower(long long int first[7][7], long long int n);
long long int sumSquareRootDecomposition(long long int arr[],
                                         vector<long long> helper,
                                         long long int n, long long int l,
                                         long long int r);
vector<long long> squareRootDecompositionSumArray(long long int arr[],
                                                  long long int n);
long long int minSquareRootDecomposition(long long int arr[],
                                         vector<long long> helper,
                                         long long int n, long long int l,
                                         long long int r);
long long int maxSquareRootDecomposition(long long int arr[],
                                         vector<long long> helper,
                                         long long int n, long long int l,
                                         long long int r);
vector<long long> squareRootDecompositionMinArray(long long int arr[],
                                                  long long int n);
vector<long long> squareRootDecompositionMaxArray(long long int arr[],
                                                  long long int n);
void updateSquareRootDecompositionMinArray(long long int arr[],
                                           vector<long long> &helper,
                                           long long int n, long long int i,
                                           long long int x);
void updateSquareRootDecompositionMaxArray(long long int arr[],
                                           vector<long long> &helper,
                                           long long int n, long long int i,
                                           long long int x);
void updateSquareRootDecompositionSumArray(long long int arr[],
                                           vector<long long> &helper,
                                           long long int n, long long int i,
                                           long long int x);
void dfs(long long int i, set<long long int> arr[], long long int visited[]);
void uni(long long int x, long long int y, long long int par[],
         long long int size[]);
long long int find(long long int x, long long int par[], long long int size[]);
long long int modulo(long long int value, long long int m);
class FenwickTree;
void pairsort(long long int a[], long long int b[], long long int n);
long long int max(long long int a, long long int b);
long long int min(long long int a, long long int b);
long long int modInverse(long long int a, long long int m);
long long int modsum(long long int a, long long int b, long long int m);
long long int modmul(long long int a, long long int b, long long int m);
string reverseOfString(string s);
long long int nCrMod(long long int n, long long int r, long long int mod);
vector<long long> kmpArray(string s);
long long int floorSqrt(long long int x);
long long int fact[1];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int q = 1;
  for (long long int currentIndex = 0; currentIndex < q; currentIndex++) {
    long long int n, m;
    cin >> n >> m;
    long long int x, k, y;
    cin >> x >> k >> y;
    long long int a[n], b[m];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (long long int i = 0; i < m; i++) cin >> b[i];
    long long int c[n];
    long long int curr = 0;
    for (long long int i = 0; i < n; i++) {
      if (curr >= m) {
        c[i] = 0;
      }
      if (a[i] == b[curr]) {
        c[i] = a[i];
        curr++;
      } else {
        c[i] = 0;
      }
    }
    if (curr < m) {
      cout << -1 << endl;
      return 0;
    }
    vector<long long> l, r, ma, t1, t2;
    for (long long int i = 0; i < n; i++) {
      if (c[i]) continue;
      long long int j = i;
      long long int max1 = a[i], maxindex = i;
      while (j < n && c[j] == 0) {
        if (a[j] > max1) {
          max1 = a[j];
          maxindex = j;
        }
        j++;
      }
      j--;
      l.push_back(i);
      r.push_back(j);
      ma.push_back(max1);
      if (i != 0)
        t1.push_back(i - 1);
      else
        t1.push_back(-1);
      if (j != n - 1)
        t2.push_back(j + 1);
      else
        t2.push_back(-1);
      i = j;
    }
    long long int f = 0;
    long long int ans = 0;
    for (long long int i = 0; i < l.size(); i++) {
      if (r[i] - l[i] + 1 < k) {
        if ((t1[i] != -1 && a[t1[i]] > ma[i]) ||
            (t2[i] != -1 && a[t2[i]] > ma[i])) {
          ans += y * (r[i] - l[i] + 1);
        } else {
          f = 1;
          break;
        }
      } else {
        ans += y * ((r[i] - l[i] + 1) % k);
        if (y * k > x) {
          ans += x * ((r[i] - l[i] + 1) / k);
        } else {
          if ((t1[i] != -1 && a[t1[i]] > ma[i]) ||
              (t2[i] != -1 && a[t2[i]] > ma[i])) {
            ans += y * ((r[i] - l[i] + 1) / k * k);
          } else {
            ans += y * (((r[i] - l[i] + 1) / k - 1) * (k)) + x;
          }
        }
      }
    }
    if (!f)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
vector<long long> kmpArray(string s) {
  vector<long long> arr(s.length(), 0);
  for (long long int i = 1; i < s.length(); i++) {
    long long int len = arr[i - 1];
    while (len > 0 && s[len] != s[i]) len = arr[len - 1];
    if (s[len] == s[i]) len++;
    arr[i] = len;
  }
  return arr;
}
long long int floorSqrt(long long int x) {
  if (x == 0 || x == 1) return x;
  long long int start = 1, end = x, ans;
  while (start <= end) {
    long long int mid = (start + end) / 2;
    if (mid * mid == x) return mid;
    if (mid * mid < x) {
      start = mid + 1;
      ans = mid;
    } else
      end = mid - 1;
  }
  return ans;
}
long long int nCrMod(long long int n, long long int r, long long int mod) {
  return (fact[n] * modInverse(fact[r], mod) % mod *
          modInverse(fact[n - r], mod) % mod) %
         mod;
}
void SieveOfEratosthenes(long long int n, bool isPrime[]) {
  isPrime[0] = isPrime[1] = false;
  for (long long int i = 2; i <= n; i++) isPrime[i] = true;
  for (long long int p = 2; p * p <= n; p++) {
    if (isPrime[p] == true) {
      for (long long int i = p * 2; i <= n; i += p) isPrime[i] = false;
    }
  }
}
string reverseOfString(string s) {
  string t;
  for (long long int i = 0; i < s.length(); i++) {
    t += s[s.length() - i - 1];
  }
  return t;
}
class FenwickTree {
 private:
  long long int n;
  long long int h(long long int i) { return (i | (i + 1)); }
  long long int g(long long int i) { return (i & (i + 1)); }

 public:
  long long int *sumtree;
  long long int *mainArray;
  FenwickTree(long long int n) {
    this->n = n;
    mainArray = (long long int *)malloc(n * sizeof(long long int));
    sumtree = (long long int *)calloc(n, sizeof(long long int));
  }
  void addElementAtIndex(long long int i, long long int x) {
    mainArray[i] = x;
    update(i, x);
  }
  void update(long long int i, long long int delta) {
    for (long long int j = i; j < n; j = h(j)) {
      sumtree[j] += delta;
    }
  }
  long long int sum(long long int i, long long int j) {
    long long int sum1 = 0, sum2 = 0;
    long long int i1 = i, j1 = j;
    while (j >= 0) {
      sum1 += sumtree[j];
      j = g(j) - 1;
    }
    while (i >= 0) {
      sum2 += sumtree[i];
      i = g(i) - 1;
    }
    return sum1 - sum2 + mainArray[i1];
  }
};
long long int modsum(long long int a, long long int b, long long int m) {
  return ((a % m) + (b % m)) % m;
}
long long int modmul(long long int a, long long int b, long long int m) {
  return ((a % m) * (b % m)) % m;
}
long long int modInverse(long long int a, long long int m) {
  return modpower(a, m - 2, m);
}
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
void pairsort(long long int a[], long long int b[], long long int n) {
  pair<long long int, long long int> pairt[n];
  for (long long int i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long int i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long int extendedGcd(long long int a, long long int b, long long int &x,
                          long long int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long int x1, y1;
  long long int d = extendedGcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
bool find_any_solution(long long int a, long long int b, long long int c,
                       long long int &x0, long long int &y0, long long int &g) {
  g = extendedGcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
string findSum(string str1, string str2) {
  if (str1.length() > str2.length()) {
    string s = str1;
    str1 = str2;
    str2 = s;
  }
  string str = "";
  int n1 = str1.length(), n2 = str2.length();
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());
  int carry = 0;
  for (int i = 0; i < n1; i++) {
    int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  for (int i = n1; i < n2; i++) {
    int sum = ((str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  if (carry) str.push_back(carry + '0');
  reverse(str.begin(), str.end());
  return str;
}
long long int binarySearch(vector<long long> arr, long long int l,
                           long long int r, long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
long long int greatestSubarraySum(long long int array[], long long int n) {
  long long int best = 0, sum = 0;
  for (long long int k = 0; k < n; k++) {
    sum = max(array[k], sum + array[k]);
    best = max(best, sum);
  }
  return best;
}
long long int modpower(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long int modulo(long long int value, long long int m) {
  long long int mod = value % m;
  if (value < 0) {
    mod += m;
  }
  return mod;
}
long long int find(long long int x, long long int par[], long long int size[]) {
  if (x == par[x])
    return x;
  else
    return par[x] = find(par[x], par, size);
}
void uni(long long int x, long long int y, long long int par[],
         long long int size[]) {
  x = find(x, par, size);
  y = find(y, par, size);
  if (size[x] > size[y]) swap(x, y);
  par[x] = y;
  size[y] += size[x];
}
void dfs(long long int i, set<long long int> arr[], long long int visited[]) {
  if (visited[i]) return;
  cout << (char)('a' + i);
  visited[i] = 1;
  for (auto u : arr[i]) dfs(u, arr, visited);
}
long long int countSetBits(long long int n) {
  long long int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
long long int flag2;
void primeFactors(long long int n, map<long long int, long long int> &arr2,
                  long long int k, long long int &flaggy) {
  long long int count = 0;
  long long int flag = 0;
  while (n % 2 == 0) {
    n = n / 2;
    count++;
  }
  if (count % k != 0) {
    flag = 1;
    arr2[2] = count % k;
  }
  count = 0;
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      n = n / i;
      count++;
    }
    if (count % k != 0) {
      flag = 1;
      arr2[i] = count % k;
    }
    count = 0;
  }
  if (n > 2) {
    if (1 % k != 0) {
      flag = 1;
      arr2[n] = 1 % k;
    }
  }
  if (flag == 0) {
    flag2++;
    flaggy = 1;
  }
}
void matrixMultiply(long long int *a[], long long int *b[], long long int n) {
  long long int mul[n][n];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      mul[i][j] = 0;
      for (long long int k = 0; k < n; k++) mul[i][j] += a[i][k] * b[k][j];
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = mul[i][j];
}
void matrixPower(long long int **first, long long int n, long long int k) {
  if (n == 1) return;
  long long int **M = (long long int **)malloc(k * sizeof(long long int *));
  for (long long int i = 0; i < k; i++) {
    M[i] = (long long int *)malloc(k * sizeof(long long int));
    for (long long int j = 0; j < k; j++) {
      M[i][j] = first[i][j];
    }
  }
  matrixPower(first, n / 2, k);
  matrixMultiply(first, first, k);
  if (n % 2 != 0) matrixMultiply(first, M, k);
}
vector<long long> squareRootDecompositionMinArray(long long int arr[],
                                                  long long int n) {
  long long int k = (long long int)ceil(sqrt(n));
  vector<long long> helper(k, std::numeric_limits<long long int>::max());
  for (long long int i = 0; i < n; i++)
    helper[i / k] = min(helper[i / k], arr[i]);
  return helper;
}
vector<long long> squareRootDecompositionMaxArray(long long int arr[],
                                                  long long int n) {
  long long int k = (long long int)ceil(sqrt(n));
  vector<long long> helper(k, -std::numeric_limits<long long int>::max());
  for (long long int i = 0; i < n; i++)
    helper[i / k] = max(helper[i / k], arr[i]);
  return helper;
}
long long int minSquareRootDecomposition(long long int arr[],
                                         vector<long long> helper,
                                         long long int n, long long int l,
                                         long long int r) {
  long long int k = (long long int)ceil(sqrt(n));
  long long int a = l / k;
  long long int b = r / k;
  long long int min1 = std::numeric_limits<long long int>::max();
  if (a == b) {
    for (long long int i = l; i < r + 1; i++) min1 = min(min1, arr[i]);
    return min1;
  }
  for (long long int i = l; i < (a + 1) * k; i++) min1 = min(min1, arr[i]);
  for (long long int i = a + 1; i < b; i++) min1 = min(min1, helper[i]);
  for (long long int i = b * k; i < r + 1; i++) min1 = min(min1, arr[i]);
  return min1;
}
long long int maxSquareRootDecomposition(long long int arr[],
                                         vector<long long> helper,
                                         long long int n, long long int l,
                                         long long int r) {
  long long int k = (long long int)ceil(sqrt(n));
  long long int a = l / k;
  long long int b = r / k;
  long long int min1 = -std::numeric_limits<long long int>::max();
  if (a == b) {
    for (long long int i = l; i < r + 1; i++) min1 = max(min1, arr[i]);
    return min1;
  }
  for (long long int i = l; i < (a + 1) * k; i++) min1 = max(min1, arr[i]);
  for (long long int i = a + 1; i < b; i++) min1 = max(min1, helper[i]);
  for (long long int i = b * k; i < r + 1; i++) min1 = max(min1, arr[i]);
  return min1;
}
vector<long long> squareRootDecompositionSumArray(long long int arr[],
                                                  long long int n) {
  long long int k = (long long int)ceil(sqrt(n));
  vector<long long> helper(k, 0);
  for (long long int i = 0; i < n; i++) helper[i / k] += arr[i];
  return helper;
}
void updateSquareRootDecompositionSumArray(long long int arr[],
                                           vector<long long> &helper,
                                           long long int n, long long int i,
                                           long long int x) {
  long long int k = (long long int)ceil(sqrt(n));
  long long int delta = x - arr[i];
  arr[i] = x;
  helper[i / k] += delta;
}
void updateSquareRootDecompositionMinArray(long long int arr[],
                                           vector<long long> &helper,
                                           long long int n, long long int i,
                                           long long int x) {
  long long int k = (long long int)ceil(sqrt(n));
  if (helper[i / k] == arr[i]) {
    if (x < arr[i])
      helper[i / k] = arr[i];
    else {
      long long int min1 = std::numeric_limits<long long int>::max();
      for (long long int j = i / k * k; j < (i / k + 1) * k; j++)
        min1 = min(min1, arr[j]);
      helper[i / k] = min1;
    }
  } else {
    helper[i / k] = min(helper[i / k], x);
  }
  arr[i] = x;
}
void updateSquareRootDecompositionMaxArray(long long int arr[],
                                           vector<long long> &helper,
                                           long long int n, long long int i,
                                           long long int x) {
  long long int k = (long long int)ceil(sqrt(n));
  if (helper[i / k] == arr[i]) {
    if (x < arr[i])
      helper[i / k] = arr[i];
    else {
      long long int min1 = -std::numeric_limits<long long int>::max();
      for (long long int j = i / k * k; j < (i / k + 1) * k; j++)
        min1 = max(min1, arr[j]);
      helper[i / k] = min1;
    }
  } else {
    helper[i / k] = max(helper[i / k], x);
  }
  arr[i] = x;
}
long long int sumSquareRootDecomposition(long long int arr[],
                                         vector<long long> helper,
                                         long long int n, long long int l,
                                         long long int r) {
  long long int k = (long long int)ceil(sqrt(n));
  long long int a = l / k;
  long long int b = r / k;
  long long int sum = 0;
  if (a == b) {
    for (long long int i = l; i < r + 1; i++) sum += arr[i];
    return sum;
  }
  for (long long int i = l; i < (a + 1) * k; i++) {
    sum += arr[i];
  }
  for (long long int i = b * k; i < r + 1; i++) sum += arr[i];
  for (long long int i = a + 1; i < b; i++) sum += helper[i];
  return sum;
}
