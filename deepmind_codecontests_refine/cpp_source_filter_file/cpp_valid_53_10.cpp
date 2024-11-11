#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.fr >> a.sc;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.fr << " " << a.sc;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const double PI = acos(-1.0);
const double eps = 1e-9;
const long long int mod = 1e9 + 7;
const long long int inf = 1LL << 30;
const int MAXN = 1e5 + 5;
const int N = 2e5 + 5;
void inarrayyy(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  return;
}
void outarrayyy(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return;
}
int sumarrayyy(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}
bool checksort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}
bool checksortdesc(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1]) {
      return false;
    }
  }
  return true;
}
int deleteElement(int arr[], int n, int i) {
  if (i < n) {
    n = n - 1;
    for (int j = i; j < n; j++) {
      arr[j] = arr[j + 1];
    }
  }
  return n;
}
bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
unsigned long long int binomialCoeff(unsigned long long int n,
                                     unsigned long long int k) {
  unsigned long long int C[k + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (unsigned long long int i = 1; i <= n; i++) {
    for (unsigned long long int j = min(i, k); j > 0; j--) {
      C[j] = C[j] + C[j - 1];
    }
  }
  return C[k];
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int finotdumpGCD(int arr[], int n) {
  int pubgult = arr[0];
  for (int i = 1; i < n; i++) {
    pubgult = gcd(arr[i], pubgult);
    if (pubgult == 1) {
      return 1;
    }
  }
  return pubgult;
}
bool checkequal(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] != arr[i + 1]) {
      return false;
    }
  }
  return true;
}
long long int sumDigits(long long int no) {
  return no == 0 ? 0 : no % 10 + sumDigits(no / 10);
}
int huehuedigits(long long int n) {
  string num = to_string(n);
  return num.size();
}
bool perfectCube(long long int N) {
  long long int cube_root;
  cube_root = round(cbrt(N));
  if (cube_root * cube_root * cube_root == N) {
    return true;
  }
  return false;
}
long long int factorial(int n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
void gareeb() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  int c = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i].second + 1 != v[i + 1].second) c++;
  }
  if (c <= k)
    cout << "YES";
  else
    cout << "NO";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    gareeb();
    cout << "\n";
  }
}
