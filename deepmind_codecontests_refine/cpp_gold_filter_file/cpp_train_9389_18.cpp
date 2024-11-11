#include <bits/stdc++.h>
using namespace std;
struct StringHash {
  unsigned long long h[110000], pow[110000];
  void calc(char *str, int b = 1234567, int len = -1) {
    if (len < 0) len = strlen(str);
    h[0] = str[0];
    pow[0] = 1;
    for (int i = 0; i < len; i++) {
      h[i + 1] = h[i] * b + str[i];
      pow[i + 1] = pow[i] * b;
    }
  }
  unsigned long long get(int i, int j) {
    return h[j + 1] - h[i] * pow[j - i + 1];
  }
} ins;
char str[110000];
int len, sa[110000];
int lcp(int a, int b) {
  int l = 0, r = min(len - a, len - b);
  if (r == l || ins.get(a, a + r - 1) == ins.get(b, b + r - 1)) return r;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (ins.get(a, a + m - 1) == ins.get(b, b + m - 1))
      l = m;
    else
      r = m;
  }
  return l;
}
bool cmp(const int &a, const int &b) {
  int l = lcp(a, b);
  if (a + l == len) return true;
  if (b + l == len) return false;
  return str[a + l] < str[b + l];
}
typedef pair<int, int> PII;
PII st[110000];
int top;
void force(string s) {
  map<string, int> mp;
  for (int len = 1; len <= s.length(); len++) {
    for (int i = 0; i + len <= s.length(); i++) {
      string sub = s.substr(i, len);
      mp[sub]++;
    }
  }
  int ans = 0;
  map<string, int>::iterator it;
  for (it = mp.begin(); it != mp.end(); ++it) {
    ans += it->second * (it->second + 1) / 2;
  }
  cout << "force: " << ans << endl;
}
int main() {
  while (scanf(" %s", str) != EOF) {
    len = strlen(str);
    ins.calc(str, 123456789, len);
    for (int i = 0; i <= len; i++) sa[i] = i;
    sort(sa, sa + len, cmp);
    long long ans = 0, sum = len * (long long)(len + 1) / 2;
    top = 0;
    for (int i = 0; i < len; i++) {
      int l = lcp(sa[i], sa[i + 1]), p = i;
      while (top && st[top].first > l) {
        int num = st[top].first - l, s = i - st[top].second + 1;
        p = st[top].second;
        if (top - 1) num = min(num, st[top].first - st[top - 1].first);
        sum -= num * (long long)s;
        ans += num * (long long)s * (s + 1) / 2;
        top--;
      }
      while (top && st[top].first == l) {
        p = st[top].second;
        top--;
      }
      st[++top] = PII(l, p);
    }
    ans += sum;
    cout << ans << '\n';
  }
}
