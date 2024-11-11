#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T Max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T Min(T a, T b) {
  return a > b ? b : a;
}
template <class T>
inline T _GCD(T a, T b) {
  if (b == 0) return a;
  return _GCD(b, a % b);
}
template <class T>
inline T _LCM(T a, T b) {
  T g = _GCD(a, b);
  return ((a / g) * b);
}
template <class T>
inline T big_mod(T a, T p, T MOD) {
  if (p == 0) return 1;
  T ret = big_mod(a, p / 2, MOD);
  ret = (ret * ret) % MOD;
  if (ret < 0) ret += MOD;
  if (p % 2) ret = (ret * a) % MOD;
  if (ret < 0) ret += MOD;
  return ret;
}
template <class T>
inline T power(T a, T p) {
  if (p == 0) return 1;
  long long ret = power(a, p / 2);
  ret = (ret * ret);
  if (p % 2) ret = (ret * a);
  return ret;
}
template <class T0, class T1, class T2>
inline T1 string_mod_ll(T0 s, T1 mm, T2 Sz) {
  T1 n = 0;
  for (int i = 0; i < Sz; i++) {
    n = n * 10 + (long long)(s[i] - '0');
    n %= mm;
  }
  return n;
}
int compare(string a, string b) {
  if (a == b) return 0;
  if (((int)a.size()) == ((int)b.size())) {
    for (int i = 0; i < ((int)a.size()); i++) {
      if (a[i] > b[i])
        return 1;
      else if (a[i] < b[i])
        return -1;
    }
    return -1;
  }
  if (((int)a.size()) > ((int)b.size())) return 1;
  return -1;
}
string string_add(string b, string a) {
  if (((int)a.size()) > ((int)b.size())) swap(a, b);
  a = string((((int)b.size()) - ((int)a.size())), '0') + a;
  int carry = 0, add;
  string res;
  for (int i = ((int)a.size()) - 1; i > -1; i--) {
    add = (int)(a[i] - '0') + (int)(b[i] - '0') + carry;
    carry = add / 10;
    res += (add % 10) + '0';
  }
  if (carry) res += carry + '0';
  reverse(res.begin(), res.end());
  return res;
}
string string_mul(string a, string b) {
  if (((int)a.size()) > ((int)b.size())) swap(a, b);
  string res, tres;
  int l = 0, carry, mul;
  for (int i = ((int)a.size()) - 1; i > -1; i--) {
    tres = string(l, '0');
    carry = 0;
    for (int j = ((int)b.size()) - 1; j > -1; j--) {
      mul = (int)(a[i] - '0') * (int)(b[j] - '0') + carry;
      carry = mul / 10;
      tres += (mul % 10) + '0';
    }
    if (carry) tres += carry + '0';
    reverse(tres.begin(), tres.end());
    res = string_add(tres, res);
    l++;
  }
  return res;
}
void cut_leading_zero(string &res) {
  int i;
  for (i = 0; i < ((int)res.size()); i++) {
    if (res[i] != '0') break;
  }
  res = res.substr(i);
  if (!((int)res.size())) res = "0";
  return;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
bool col[2000][2000];
int main() {
  int n, val;
  memset(col, (0), sizeof(col));
  ;
  int i, j, k, id = 2;
  cin >> val;
  int mx = 0, nid = 2;
  for (i = (31 - 1); i > (1 - 1); (i)--) {
    if (val - (1 << i) >= 0) {
      mx = max(i, mx);
      val -= (1 << i);
      if (i == mx) {
        col[0][id] = 1;
        col[0][++id] = 1;
        int pr1 = id - 1, pr2 = id;
        int n1 = pr1, n2 = pr2;
        j = 1;
        for (j = (1); j < (i); (j)++) {
          n1 = id + 1;
          n2 = n1 + 1;
          id = n2;
          col[pr1][n1] = col[pr1][n2] = 1;
          col[pr2][n1] = col[pr2][n2] = 1;
          pr1 = n1;
          pr2 = n2;
        }
        col[n1][1] = 1;
        col[n2][1] = 1;
        id++;
        nid = id;
      } else {
        id = 2;
        col[0][id] = 1;
        col[0][++id] = 1;
        int pr1 = id - 1, pr2 = id;
        int n1 = pr1, n2 = pr2;
        j = 1;
        for (j = (1); j < (i); (j)++) {
          n1 = id + 1;
          n2 = n1 + 1;
          id = n2;
          col[pr1][n1] = col[pr1][n2] = 1;
          col[pr2][n1] = col[pr2][n2] = 1;
          pr1 = n1;
          pr2 = n2;
        }
        id++;
        j++;
        col[pr1][nid] = 1;
        col[pr2][nid] = 1;
        for (j = (j); j < (mx); (j)++) {
          col[nid][nid + 1] = 1;
          nid++;
        }
        col[nid][1] = 1;
        col[nid][1] = 1;
        nid++;
      }
    }
  }
  id = nid;
  if (val) {
    col[0][id] = 1;
    for (i = (1); i < (mx); (i)++) {
      col[id][id + 1] = 1;
      id++;
    }
    col[id][1] = 1;
    id++;
  }
  cout << id << endl;
  for (i = (0); i < (id); (i)++) {
    for (j = (0); j < (id); (j)++) {
      col[i][j] |= col[j][i];
    }
  }
  for (i = (0); i < (id); (i)++) {
    for (j = (0); j < (id); (j)++) {
      if (col[i][j])
        printf("Y");
      else
        printf("N");
    }
    puts("");
  }
  return 0;
}
