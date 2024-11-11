#include <bits/stdc++.h>
using namespace std;
bool is_Smaller_str(string str1, string str2) {
  long long n1 = str1.length(), n2 = str2.length();
  if (n1 < n2) return true;
  if (n2 < n1) return false;
  for (int i = 0; i < n1; i++)
    if (str1[i] < str2[i])
      return true;
    else if (str1[i] > str2[i])
      return false;
  return false;
}
string find_Diff_str(string str1, string str2) {
  if (is_Smaller_str(str1, str2)) swap(str1, str2);
  string str = "";
  long long n1 = str1.length(), n2 = str2.length();
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());
  long long carry = 0;
  for (long long i = 0; i < n2; i++) {
    long long sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
    if (sub < 0) {
      sub = sub + 10;
      carry = 1;
    } else
      carry = 0;
    str.push_back(sub + '0');
  }
  for (long long i = n2; i < n1; i++) {
    long long sub = ((str1[i] - '0') - carry);
    if (sub < 0) {
      sub = sub + 10;
      carry = 1;
    } else
      carry = 0;
    str.push_back(sub + '0');
  }
  reverse(str.begin(), str.end());
  return str;
}
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long Rselect(vector<long long> v, long long i, long long l, long long r);
long long partition(vector<long long> v, long long l, long long r);
void scanc(vector<char>& v, long long n) {
  for (long long i = 0; i < n; i++) {
    char num;
    cin >> num;
    v.push_back(num);
  }
}
void scanP(vector<pair<long long, long long> >& v, long long n) {
  for (long long i = 0; i < n; i++) {
    long long num1, num2;
    cin >> num1 >> num2;
    pair<long long, long long> p = {num1, num2};
    v.push_back(p);
  }
}
template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& vec) {
  for (auto& i : vec) {
    stream << i << ' ';
  }
  stream << '\n';
  return stream;
}
template <class T>
istream& operator>>(istream& stream, vector<T>& vec) {
  for (auto& i : vec) {
    stream >> i;
  }
  return stream;
}
void solve();
void scanN(vector<long long>& v, long long n) {
  for (long long i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
}
void scans(vector<string>& v, long long n) {
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
}
long long modfactorial(long long n, long long p) {
  if (n >= p) return 0;
  long long result = 1;
  for (long long i = 1; i < n + 1; i++) {
    result = result * i;
    result = result % p;
  }
  return result;
}
long long MI(long long a, long long b, long long s0 = 1, long long s1 = 0) {
  long long k = b;
  if (b == 0)
    return s0;
  else {
    return MI(b, a % b, s1, s0 - s1 * (a / b));
  }
}
long long choose(long long a, long long b, long long c) {
  if (a < b) return 0;
  long long x = modfactorial(a, c);
  long long y = modfactorial(b, c);
  long long z = modfactorial(a - b, c);
  long long y_ = MI(y, c, 1, 0);
  if (y_ < 0) y_ = y_ + c;
  long long z_ = MI(z, c, 1, 0);
  if (z_ < 0) z_ = z_ + c;
  long long mul = (x * y_) % c;
  mul = (mul * z_) % c;
  return mul;
}
void SOLT() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
long long modpow(long long n, long long p, long long k) {
  n = n % k;
  long long res = 1;
  while (p > 0) {
    if (p % 2 == 1) res = res * n % k;
    n = n * n % k;
    p = p / 2;
  }
  return res;
}
bool isPrime(long long a) {
  for (long long i = 2; i * i <= a; ++i)
    if (a % i == 0) return false;
  return true;
}
bool useflushdivisible(long long a) {
  cout << a << endl;
  fflush(stdout);
  char sl[10];
  scanf("%s", sl);
  return sl[0] == 'y' || sl[0] == 'Y';
}
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n = n / i;
      result = result - result / i;
    }
  }
  if (n > 1) result = result - result / n;
  return result;
}
bool cmp(pair<long long, pair<long long, long long> > x,
         pair<long long, pair<long long, long long> > y) {
  return x.first < y.first;
}
vector<long long> getfactors(long long n) {
  vector<long long> factors;
  for (long long i = 1; i < sqrt(n) + 1; i++) {
    if (n % i == 0) {
      factors.push_back(i);
      if (i != (n / i)) factors.push_back(n / i);
    }
  }
  return factors;
}
int main() {
  FAST();
  srand(time(0));
  int test = 1;
  for (int tt = 1; tt <= test; tt++) solve();
  return 0;
}
void solve() {
  string b, n;
  long long c;
  cin >> b >> n >> c;
  long long k = b.size();
  if (c == 1) {
    cout << "1" << endl;
    return;
  }
  vector<long long> mod(k + 1);
  mod[0] = 1;
  for (long long i = 1; i < k + 1; i++) {
    mod[i] = 10 * mod[i - 1];
    mod[i] %= c;
  }
  long long rem = 0;
  for (long long i = k - 1; i > -1; i--) {
    long long num = b[i] - '0';
    num *= mod[k - 1 - i];
    num %= c;
    rem += num;
    rem %= c;
  }
  rem %= c;
  long long tr = n.size();
  long long ans = rem;
  vector<long long> modn(tr + 1);
  modn[0] = 1;
  for (long long i = 1; i < tr + 1; i++) {
    modn[i] = 10 * modn[i - 1];
    modn[i] %= c;
  }
  long long time_pass = n[0] - '0';
  ans = modpow(rem, time_pass, c);
  for (long long i = 1; i < tr; i++) {
    time_pass = n[i] - '0';
    ans = modpow(ans, 10, c);
    ans *= modpow(rem, time_pass, c);
    ans %= c;
  }
  if (ans <= 0) ans += c;
  string nd;
  bool d = 0;
  nd.push_back('1');
  string kt = find_Diff_str(n, nd);
  long long ans1 = 0;
  if (kt.size()) time_pass = kt[0] - '0';
  if (kt.size()) ans1 = modpow(rem, time_pass, c);
  for (long long i = 1; i < kt.size(); i++) {
    time_pass = kt[i] - '0';
    ans1 = modpow(ans1, 10, c);
    ans1 *= modpow(rem, time_pass, c);
    ans1 %= c;
  }
  ans1 %= c;
  if (ans1 <= 0) ans1 += c;
  ans -= ans1;
  while (ans <= 0) ans += c;
  cout << ans << endl;
}
long long Rselect(vector<long long> v, long long i, long long l, long long r) {
  if (l == r) return v[l];
  long long pivot = partition(v, l, r);
  if (pivot == i)
    return v[pivot - 1];
  else if (pivot < i) {
    return Rselect(v, i, pivot, r);
  } else {
    return Rselect(v, i, l, pivot - 2);
  }
}
long long partition(vector<long long> v, long long l, long long r) {
  long long pivot_index = rand() % (r - l + 1) + l;
  swap(v[pivot_index], v[l]);
  long long i = l + 1, j = l + 1;
  while (j <= r) {
    if (v[j] < v[l]) {
      swap(v[j], v[i]);
      i++;
    }
    j++;
  }
  swap(v[l], v[i - 1]);
  return i;
}
