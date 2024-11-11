#include <bits/stdc++.h>
using namespace std;
const int infi = 1e9;
const long long int infl = 1e18;
const int MOD = 1e9 + 7;
long long int log_2(long long int n) {
  return (n > 1ll) ? 1ll + log_2(n / 2) : 0ll;
}
inline void add(long long int &a, long long int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline void sub(long long int &a, long long int b) {
  a -= b;
  if (a < 0) a += MOD;
}
inline string IntToString(long long int a) {
  char x[100];
  sprintf(x, "%lld", a);
  string s = x;
  return s;
}
inline long long int StringToInt(string a) {
  char x[100];
  long long int res;
  strcpy(x, a.c_str());
  sscanf(x, "%lld", &res);
  return res;
}
inline string GetString(void) {
  char x[1000005];
  scanf("%s", x);
  string s = x;
  return s;
}
inline string uppercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
inline string lowercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
inline void OPEN(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void showarr(long long int arr[], long long int n) {
  int i;
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void showvec(vector<long long int> v) {
  int i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
int isPalindrome(string str) {
  int l = 0;
  int h = str.length() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return 0;
    }
  }
  return 1;
}
void showvecpair(vector<pair<long long int, long long int> > v) {
  for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
string maxpal(string s) {
  int i;
  char ch = s[0];
  for (i = s.length() - 1; i >= 0; i--) {
    if (s[i] == s[0])
      if (isPalindrome(s.substr(0, i + 1))) return s.substr(0, i + 1);
  }
}
void solve() {
  long long int l, n, i, j, max = INT_MIN, min = INT_MAX, ctr = 0, cnt = 0,
                            cnt1 = 0, cnt2 = 0;
  string s;
  cin >> s;
  string str1, str2, str = "", strr;
  n = s.length();
  if (n == 1) {
    cout << s << endl;
  } else {
    for (i = 0; i < n; i++) {
      if (i < (n - 1 - i)) {
        if (s[i] == s[n - 1 - i]) {
          cnt++;
        } else {
          break;
        }
      }
    }
    str1 = s.substr(cnt, n - 2 * cnt);
    str2 = str1;
    reverse(str2.begin(), str2.end());
    str = str1 + "#" + str2;
    strr = str2 + "#" + str1;
    vector<long long int> pi(str.length() + 1, 0), pir(str.length() + 1, 0);
    pi[0] = 0;
    pir[0] = 0;
    for (i = 1; i < str.length(); i++) {
      j = pi[i - 1];
      while (j > 0 && str[i] != str[j]) j = pi[j - 1];
      if (str[i] == str[j]) {
        j++;
      }
      pi[i] = j;
    }
    for (i = 1; i < strr.length(); i++) {
      j = pir[i - 1];
      while (j > 0 && strr[i] != strr[j]) j = pir[j - 1];
      if (strr[i] == strr[j]) {
        j++;
      }
      pir[i] = j;
    }
    if (pi[str.length() - 1] > pir[str.length() - 1]) {
      if (pi[str.length() - 1] == 0) {
        for (i = 0; i < cnt + pi[str.length() - 1]; i++) {
          cout << s[i];
        }
        if (cnt < n) cout << s[i];
        for (i = n - cnt; i < n; i++) cout << s[i];
        cout << endl;
      } else {
        for (i = 0; i < cnt + pi[str.length() - 1]; i++) {
          cout << s[i];
        }
        for (i = n - cnt; i < n; i++) cout << s[i];
        cout << endl;
      }
    } else {
      if (pir[str.length() - 1] == 0) {
        for (i = 0; i < cnt + pir[str.length() - 1]; i++) {
          cout << s[i];
        }
        if (2 * cnt < n) cout << s[i];
        for (i = n - cnt; i < n; i++) cout << s[i];
        cout << endl;
      } else {
        for (i = 0; i < cnt; i++) {
          cout << s[i];
        }
        for (i = n - cnt - pir[str.length() - 1]; i < n; i++) cout << s[i];
        cout << endl;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, T;
  cin >> T;
  for (i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
