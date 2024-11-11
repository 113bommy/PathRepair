#include <bits/stdc++.h>
using namespace std;
bool nuo(int k, string s, string a, string b, char p[26], bool used[26], int i0,
         char c) {
  if (a[i0] > c || b[i0] < c) return false;
  string res;
  for (int i = 0; i < k; i++) {
    if (!used[i]) res += (char)('a' + i);
  }
  if (a[i0] < c && c < b[i0]) {
    int t = 0;
    cout << "YES"
         << "\n";
    for (int i = 0; i < k; i++) {
      if (p[i] == 'X') {
        cout << res[t];
        t++;
      } else {
        cout << p[i];
      }
    }
    cout << "\n";
    return true;
  }
  if (a[i0] == c)
    sort(res.begin(), res.end(), greater<char>());
  else
    sort(res.begin(), res.end());
  int n = s.size();
  int t = 0;
  for (int i = i0 + 1; i < n; i++) {
    if (p[s[i] - 'a'] == 'X') {
      p[s[i] - 'a'] = res[t];
      t++;
    }
  }
  for (int i = 0; i < k; i++) {
    if (p[i] == 'X') {
      p[i] = res[t];
      t++;
    }
  }
  string s2;
  for (int i = 0; i < n; i++) {
    s2 += p[s[i] - 'a'];
  }
  if (a <= s2 && s2 <= b) {
    cout << "YES"
         << "\n";
    for (int i = 0; i < k; i++) cout << p[i];
    cout << "\n";
    return true;
  } else {
    return false;
  }
}
void solve(int k, string s, string a, string b) {
  char p[26];
  fill(p, p + k, 'X');
  bool used[26] = {};
  int n = s.size();
  int i0 = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if ((p[s[i] - 'a'] != 'X' && p[s[i] - 'a'] != a[i]) ||
          (p[s[i] - 'a'] == 'X' && used[a[i] - 'a'])) {
        cout << "NO"
             << "\n";
        return;
      }
      p[s[i] - 'a'] = a[i];
      used[a[i] - 'a'] = 1;
      continue;
    } else {
      i0 = i;
      break;
    }
  }
  if (i0 == -1) {
    string res;
    for (int i = 0; i < k; i++) {
      if (!used[i]) res += ('a' + i);
    }
    int t = 0;
    cout << "YES"
         << "\n";
    for (int i = 0; i < k; i++) {
      if (p[i] != 'X')
        cout << p[i];
      else {
        cout << res[t];
        t++;
      }
    }
    cout << "\n";
    return;
  }
  if (p[s[i0] - 'a'] != 'X') {
    if (!nuo(k, s, a, b, p, used, i0, p[s[i0] - 'a'])) {
      cout << "NO"
           << "\n";
    }
    return;
  }
  for (int i = (a[i0] - 'a') + 1; i < (b[i0] - 'a'); i++) {
    if (used[i]) continue;
    char p1[26];
    bool used1[26];
    for (int j = 0; j < k; j++) p1[j] = p[j], used1[j] = used[j];
    p1[s[i0] - 'a'] = ('a' + i);
    used1[i] = 1;
    if (nuo(k, s, a, b, p1, used1, i0, (char)('a' + i))) return;
  }
  if (!used[a[i0] - 'a']) {
    char p1[26];
    bool used1[26];
    for (int j = 0; j < k; j++) p1[j] = p[j], used1[j] = used[j];
    p1[s[i0] - 'a'] = a[i0];
    used1[a[i0] - 'a'] = 1;
    if (nuo(k, s, a, b, p1, used1, i0, a[i0])) return;
  }
  if (!used[b[i0] - 'a']) {
    char p1[26];
    bool used1[26];
    for (int j = 0; j < k; j++) p1[j] = p[j], used1[j] = used[j];
    p1[s[i0] - 'a'] = b[i0];
    used1[b[i0] - 'a'] = 1;
    if (nuo(k, s, a, b, p1, used1, i0, b[i0])) return;
  }
  cout << "NO"
       << "\n";
}
int main() {
  int t;
  cin >> t;
  char s0[1000001], a0[1000001], b0[1000001];
  for (int i = 0; i < t; i++) {
    int k;
    scanf("%d", &k);
    scanf("%s", s0);
    scanf("%s", a0);
    scanf("%s", b0);
    if (strlen(s0) == 1) {
      printf("YES\n");
      for (int j = 0; j < k; j++) {
        if ((s0[0] - 'a') == j)
          printf("%c", a0[0]);
        else if ((a0[0] - 'a') == j)
          printf("%c", s0[0]);
        else
          printf("%c", (char)('a' + j));
      }
      printf("\n");
      continue;
    }
    int n = strlen(s0);
    string s(s0, n), a(a0, n), b(b0, n);
    solve(k, s, a, b);
  }
  return 0;
}
