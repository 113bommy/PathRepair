#include <bits/stdc++.h>
using namespace std;
multiset<long long> LIS(vector<long long> A) {
  long long a = A.size();
  multiset<long long> S;
  multiset<long long>::iterator it;
  for (long long i = 0; i <= a - 1; i++) {
    S.insert(A[i]);
    it = S.upper_bound(A[i]);
    if (it != S.end()) S.erase(it);
  }
  return S;
}
multiset<long long> LSIS(vector<long long> A) {
  long long a = A.size();
  multiset<long long> S;
  multiset<long long>::iterator it;
  for (long long i = 0; i <= a - 1; i++) {
    S.insert(A[i]);
    it = S.lower_bound(A[i]);
    it++;
    if (it != S.end()) S.erase(it);
  }
  return S;
}
long long gcd(long long a, long long b) {
  if (a == 0) return (b);
  return (gcd(b % a, a));
}
long long extGcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return (b);
  }
  long long a1, b1, c, x1, y1, rst;
  a1 = b % a;
  b1 = a;
  c = b / a;
  rst = extGcd(a1, b1, x1, y1);
  x = y1 - c * x1;
  y = x1;
  return (rst);
}
bool suspect(long long b, long long t, long long u, long long n) {
  long long prod = 1;
  while (u) {
    if (u & 1) prod = ((prod * b) % n);
    b = ((b * b) % n);
    u /= 2;
  }
  if (prod == 1) return true;
  for (long long i = 1; i <= t; i++) {
    if (prod == n - 1) return true;
    prod = (prod * prod) % n;
  }
  return false;
}
bool isprime(long long n) {
  long long k = n - 1;
  long long t = 0;
  while (!(k % 2)) {
    t++;
    k /= 2;
  }
  if (n > 2 && n % 2 == 0) return 0;
  if (n > 3 && n % 3 == 0) return 0;
  if (n > 5 && n % 5 == 0) return 0;
  if (n > 7 && n % 7 == 0) return 0;
  if (suspect(61, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n))
    return true;
  return false;
}
bool isprimell(unsigned long long n) {
  long long k = n - 1;
  long long t = 0;
  while (!(k % 2)) {
    t++;
    k /= 2;
  }
  if (n > 2 && n % 2 == 0) return 0;
  if (n > 3 && n % 3 == 0) return 0;
  if (n > 5 && n % 5 == 0) return 0;
  if (n > 7 && n % 7 == 0) return 0;
  if (suspect(3, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n) &&
      suspect(5, t, k, n) && suspect(11, t, k, n) && suspect(13, t, k, n) &&
      suspect(17, t, k, n) && suspect(19, t, k, n) && suspect(19, t, k, n) &&
      suspect(23, t, k, n) && suspect(29, t, k, n) && suspect(31, t, k, n) &&
      suspect(37, t, k, n))
    return true;
  return false;
}
long long __stoll(string x) {
  long long k = 0;
  for (long long i = 0; i <= x.size() - 1; i++) {
    k = k * 10 + (x[i] - '0');
  }
  return k;
}
vector<long long> __baseForSeg[2000];
class SegTree {
  SegTree *L = NULL, *R = NULL;
  long long idxl, idxr;
  long long ans;
  long long x;

 public:
  void getbase(vector<long long>& a, long long k) {
    __baseForSeg[k] = a;
    x = k;
    idxl = 0;
    idxr = a.size() - 1;
  }
  void update() {
    if (idxl == idxr) {
      ans = __baseForSeg[x][idxl];
      return;
    }
    if (idxl > idxr) {
      ans = 0;
      return;
    } else {
      long long mid = (idxl + idxr) / 2;
      if (L == NULL) {
        L = new SegTree;
        L->idxl = idxl;
        L->idxr = mid;
        L->x = x;
      }
      L->update();
      if (R == NULL) {
        R = new SegTree;
        R->idxl = mid + 1;
        R->idxr = idxr;
        R->x = x;
      }
      R->update();
      ans = L->ans + R->ans;
    }
  }
  void out() {
    cout << this->ans << endl;
    for (int _ = 0; _ < __baseForSeg[x].size(); _++)
      cout << __baseForSeg[x][_] << ' ';
    cout << endl;
  }
  long long searchn(SegTree* a, long long l, long long r) {
    if (a->idxl >= l && a->idxr <= r) return a->ans;
    if (a->idxl > r || a->idxr < l) return 0;
    return searchn(a->L, l, r) + searchn(a->R, l, r);
  }
  long long search(long long l, long long r) {
    if (idxl >= l && idxr <= r) return ans;
    if (idxl > r || idxr < l) return 0;
    return searchn(this->L, l, r) + searchn(this->R, l, r);
  }
  void updatenum(long long a, long long idx) {
    if (idx > idxr || idx < idxl) return;
    if (idxr == idxl) return;
    ans += (a - __baseForSeg[x][idx]);
    L->updatenum(a, idx);
    R->updatenum(a, idx);
  }
  void afterupdate(long long a, long long idx) { __baseForSeg[x][idx] = a; }
};
string __to_string(long long a) {
  if (a == 0) return "0";
  string k = "";
  long long p = 0;
  if (a < 0) {
    p = 1;
    a = -a;
  }
  while (a) {
    k = (char)((a % 10) + '0') + k;
    a /= 10;
  }
  if (p) k = '-' + k;
  return k;
}
bool bigger(string a, string b) {
  if (a.length() > b.length()) return true;
  if (a.length() < b.length()) return false;
  for (long long i = 0; i <= a.length() - 1; i++) {
    if (a[i] > b[i])
      return true;
    else if (a[i] < b[i])
      return false;
  }
  return false;
}
string add(string str1, string str2) {
  if (str1.length() > str2.length()) swap(str1, str2);
  string str = "";
  int n1 = str1.length(), n2 = str2.length();
  int diff = n2 - n1;
  int carry = 0;
  for (int i = n1 - 1; i >= 0; i--) {
    int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  for (int i = n2 - n1 - 1; i >= 0; i--) {
    int sum = ((str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  if (carry) str.push_back(carry + '0');
  reverse(str.begin(), str.end());
  return str;
}
string sub(string str1, string str2) {
  if (bigger(str2, str1)) swap(str1, str2);
  string str = "";
  int n1 = str1.length(), n2 = str2.length();
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());
  int carry = 0;
  for (int i = 0; i < n2; i++) {
    int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
    if (sub < 0) {
      sub = sub + 10;
      carry = 1;
    } else
      carry = 0;
    str.push_back(sub + '0');
  }
  for (int i = n2; i < n1; i++) {
    int sub = ((str1[i] - '0') - carry);
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
string mul(string A, string B) {
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  string C;
  C.resize(A.length() + B.length(), '0');
  for (long long i = 0; i <= A.length() - 1; i++) {
    int c = 0;
    for (long long j = 0; j <= B.length() - 1; j++) {
      c += ((A[i] - '0') * (B[j] - '0') + C[i + j] - '0');
      C[i + j] = (char)(c % 10 + '0');
      c /= 10;
    }
    if (c > 0) C[i + B.length()] += c;
  }
  reverse(C.begin(), C.end());
  return C;
}
string div(string number, long long divisor) {
  string ans;
  long long idx = 0;
  long long temp = number[idx] - '0';
  while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
  while (number.size() > idx) {
    ans += (temp / divisor) + '0';
    temp = (temp % divisor) * 10 + number[++idx] - '0';
  }
  if (ans.length() == 0) return "0";
  return ans;
}
long double PI = 3.14159265358979323846;
void Process() {
  vector<long long> C;
  C.push_back(1);
  for (long long i = 1; i <= 10000; i++) {
    C.push_back((1 << i) - 1);
    if (C.back() > 10000) break;
  }
  long long a, b;
  cin >> b >> a;
  long long st = 1;
  vector<pair<long long, long long> > X;
  long long k = 0;
  while (b) {
    if (st > 1e18 - a) break;
    long long t = upper_bound(C.begin(), C.end(), b) - C.begin();
    t--;
    X.push_back({st, t - 1});
    b -= C[t];
    k += (t);
    st += a;
  }
  if (b) {
    cout << -1 << endl;
    return;
  }
  if (k > 10000) {
    cout << -1 << endl;
    return;
  }
  cout << k << endl;
  for (long long i = 0; i <= X.size() - 1; i++) {
    for (long long j = 0; j <= X[i].second; j++) cout << X[i].first << ' ';
  }
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  Process();
}
