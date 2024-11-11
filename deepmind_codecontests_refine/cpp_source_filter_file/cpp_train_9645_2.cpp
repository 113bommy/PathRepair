#include <bits/stdc++.h>
using namespace std;
int L_Search(vector<int> &v, int x);
int B_Search(vector<int> &v, int x);
string LCS(const string &s1, const string &s2);
void Insert_Single(vector<int> &v, int val);
void Insert_Multiple(vector<int> &v, int val);
void M_Sort(vector<int> &P);
void Merge(vector<int> &P, vector<int> &L, vector<int> &R);
map<char, int> Get_Char_Count(string s);
map<char, vector<int> > Get_Char_Indexes(string s);
map<int, int> Get_int_Count(vector<int> &s);
void setBit(int &n, int pos, bool val);
bool getBit(const int &n, int pos);
int getDigit(int n, int pos);
void setDigit(int &n, int pos, int val);
int digit_count(int n);
int power(int b, int p);
int SOD(int n);
int POD(int n);
bool isPalindrom(string &s);
void GenPrimes(vector<int> &v, int n);
bool isPrime(int n);
class fib {
 private:
  vector<long long int> M;

 public:
  fib(int max_size) { M.resize(max_size, 0); }
  long long int get(int N) {
    if (N == 0)
      return (0);
    else if (N < 3)
      return (M[N] = 1);
    else {
      if (M[N])
        return M[N];
      else {
        int k = (N & 1) ? (N + 1) / 2 : N / 2;
        M[N] = (N & 1) ? (get(k) * get(k) + get(k - 1) * get(k - 1))
                       : (2 * get(k - 1) + get(k)) * get(k);
        return M[N];
      }
    }
  }
};
int main() {
  int n;
  cin >> n;
  vector<int> N(n);
  for (int i = 0; i < n; ++i) cin >> N[i];
  map<int, int> M = Get_int_Count(N);
  int count = 0;
  for (auto i = M.begin(); i != M.end(); ++i) {
    if ((*i).second) ++count;
  }
  cout << count;
  return (0);
}
string LCS(const string &s1, const string &s2) {
  int s1_sz = s1.size(), s2_sz = s2.size();
  int X[s1_sz + 1][s2_sz + 1];
  int i = 0;
  while (i <= s1_sz) X[i++][0] = 0;
  int j = 0;
  while (j <= s2_sz) X[0][j++] = 0;
  for (i = 1; i <= s1_sz; ++i) {
    for (j = 1; j <= s2_sz; ++j) {
      if (s1[i] == s2[j])
        X[i][j] = X[i - 1][j - 1] + 1;
      else
        X[i][j] = max(X[i][j - 1], X[i - 1][j]);
    }
  }
  int L = X[s1_sz][s2_sz];
  string ret;
  for (i = s1_sz, j = s2_sz; ret.length() < L;) {
    if (s1[i - 1] == s2[j - 1]) {
      ret += s1[i - 1];
      --i;
      --j;
    } else {
      if (X[i - 1][j] >= X[i][j - 1])
        i -= 1;
      else
        j -= 1;
    }
  }
  return (ret);
}
int L_Search(vector<int> &v, int x) {
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == x) return (i);
  }
  return (-1);
}
int B_Search(vector<int> &v, int x) {
  int s = 0, e = v.size(), m = (s + e) / 2;
  while (s <= e) {
    if (x > v[m])
      s = m + 1;
    else if (x < v[m])
      e = m - 1;
    else
      return (m);
    m = (s + e) / 2;
  }
  return (-1);
}
void Insert_Multiple(vector<int> &v, int val) {
  int s = 0, e = v.size(), m = (s + e) / 2;
  while (s <= e) {
    if (val > v[m])
      s = m + 1;
    else if (val < v[m])
      e = m - 1;
    else
      break;
    m = (s + e) / 2;
  }
  v.insert(v.begin() + m, val);
}
void Insert_Single(vector<int> &v, int val) {
  int s = 0, e = v.size(), m = (s + e) / 2;
  while (s <= e) {
    if (val > v[m])
      s = m + 1;
    else if (val < v[m])
      e = m - 1;
    else
      return;
    m = (s + e) / 2;
  }
  v.insert(v.begin() + m, val);
}
void M_Sort(vector<int> &P) {
  if (P.size() > 1) {
    unsigned int Par_sz = P.size(), L_sz = Par_sz / 2, R_sz = Par_sz - L_sz, i;
    vector<int> L(L_sz), R(R_sz);
    for (i = 0; i < L_sz; ++i) L[i] = P[i];
    for (int j = 0; i < Par_sz; ++i, ++j) R[j] = P[i];
    M_Sort(L);
    M_Sort(R);
    Merge(P, L, R);
  }
}
void Merge(vector<int> &P, vector<int> &L, vector<int> &R) {
  int i = 0, j = 0, k = 0;
  while (i < L.size() && j < R.size()) {
    P[k++] = (L[i] <= R[j] ? L[i++] : R[j++]);
  }
  while (i < L.size()) P[k++] = L[i++];
  while (j < R.size()) P[k++] = R[j++];
}
map<char, int> Get_Char_Count(string s) {
  map<char, int> M;
  for (int i = 0; i < s.size(); ++i) M[s[i]] += 1;
  return (M);
}
map<int, int> Get_int_Count(vector<int> &s) {
  map<int, int> M;
  for (int i = 0; i < s.size(); ++i) M[s[i]] += 1;
  return (M);
}
map<char, vector<int> > Get_Char_Indexes(string s) {
  map<char, vector<int> > M;
  for (int i = 0; i < s.size(); ++i) M[s[i]].push_back(i);
  return (M);
}
int digit_count(int n) {
  int count = 0;
  while (n) {
    ++count;
    n /= 10;
  }
  return (count);
}
int getDigit(int n, int pos) {
  if (digit_count(n) < pos) {
    return (-1);
  } else {
    int ret = -1;
    while (pos--) {
      ret = n % 10;
      n /= 10;
    }
    return (ret);
  }
}
void setDigit(int &n, int pos, int val) {
  if (digit_count(n) < pos)
    return;
  else {
    int tmp = getDigit(n, pos);
    tmp = val - tmp;
    n = n + tmp * power(10, pos - 1);
  }
}
int power(int b, int p) {
  int ans = 1;
  while (p--) ans *= b;
  return (ans);
}
void setBit(int &n, int pos, bool val) {
  val ? n |= (1 << (pos - 1)) : n &= ~(1 << (pos - 1));
}
bool getBit(const int &n, int pos) { return (n & (1 << (pos - 1))); }
int SOD(int n) {
  int s = 0;
  while (n) {
    s += n % 10;
    n /= 10;
  }
  return (s);
}
int POD(int n) {
  int p = 1;
  int tmp;
  while (n) {
    tmp = n % 10;
    if (tmp) p *= tmp;
    n /= 10;
  }
  return (p);
}
void GenPrimes(vector<int> &v, int n) {}
bool isPrime(long long int n) {
  if (n < 2)
    return (false);
  else if (n < 4)
    return (true);
  else if (!(n % 2) || !(n % 3))
    return (false);
  else {
    for (long long int i = 5; i * i <= n; i += 6) {
      if (!(n % i) || !(n % (i + 2))) return (false);
    }
  }
  return (true);
}
void Factorize3(vector<long long int> &v, long long int n) {
  while (!(n % 2)) {
    v.push_back(2);
    n /= 2;
  }
  while (!(n % 3)) {
    v.push_back(3);
    n /= 3;
  }
  for (unsigned long long int i = 5; i * i <= n; i += 6) {
    while (!(n % i)) {
      v.push_back(i);
      n /= i;
    }
  }
  for (unsigned long long int i = 7; i * i <= n; i += 6) {
    while (!(n % i)) {
      v.push_back(i);
      n /= i;
    }
  }
  if (n > 2) v.push_back(n);
}
bool isPalindrom(string &s) {
  int start = 0, end = s.size() - 1;
  while (start <= end) {
    if (s[start] != s[end]) return (false);
    ++start;
    --end;
  }
  return (true);
}
