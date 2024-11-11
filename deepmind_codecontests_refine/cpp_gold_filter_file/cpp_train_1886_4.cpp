#include <bits/stdc++.h>
void compute_lps_array(std::string &pat, int m, int *lps);
int kmp_search(std::string &pat, std::string &txt) {
  int m = pat.length();
  int n = txt.length();
  int *lps = new int[m];
  compute_lps_array(pat, m, lps);
  int j = 0;
  int i = 0;
  while (i < n) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == m) {
      delete[] lps;
      return i - j;
      j = lps[j - 1];
    } else if (i < n && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
  delete[] lps;
  return -1;
}
void compute_lps_array(std::string &pat, int m, int *lps) {
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < m) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0)
        len = lps[len - 1];
      else {
        lps[i] = 0;
        i++;
      }
    }
  }
}
std::string a[3005] = {};
std::string b[3005] = {};
bool must[3005] = {};
int l[3005] = {};
int r[3005] = {};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n, mx, mx_i;
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = 0; i < n; i++) std::cin >> b[i];
  mx = -1;
  mx_i = -1;
  for (int i = 0; i < n; i++) {
    l[i] = -1;
    r[i] = -1;
    for (int j = 0; j < (int)a[i].length(); j++) {
      must[j] = false;
      if (a[i].at(j) != b[i].at(j)) must[j] = true;
    }
    for (int j = 0; j < (int)a[i].length(); j++) {
      if (must[j]) {
        l[i] = j;
        break;
      }
    }
    for (int j = ((int)a[i].length()) - 1; j >= 0; j--) {
      if (must[j]) {
        r[i] = j;
        break;
      }
    }
    if (l[i] != -1) {
      if (r[i] - l[i] + 1 > mx) {
        mx = r[i] - l[i] + 1;
        mx_i = i;
      }
    }
  }
  std::string s = a[mx_i].substr(l[mx_i], mx);
  bool fail = false;
  for (int i = 0; i < n; i++) {
    if (l[i] != -1) {
      std::string t = a[i].substr(l[i], r[i] - l[i] + 1);
      if (t != s) fail = true;
    }
  }
  if (fail)
    std::cout << "NO\n";
  else {
    while (l[mx_i] > 0) {
      bool fail = false;
      char req = a[mx_i].at(l[mx_i] - 1);
      for (int i = 0; i < n; i++) {
        if (l[i] != -1) {
          if (l[i] > 0 && a[i].at(l[i] - 1) == req)
            ;
          else
            fail = true;
        }
      }
      if (fail)
        break;
      else {
        for (int i = 0; i < n; i++) {
          if (l[i] != -1) l[i]--;
        }
      }
    }
    while (r[mx_i] + 1 < (int)a[mx_i].length()) {
      bool fail = false;
      char req = a[mx_i].at(r[mx_i] + 1);
      for (int i = 0; i < n; i++) {
        if (l[i] != -1) {
          if (r[i] + 1 < (int)a[i].length() && a[i].at(r[i] + 1) == req)
            ;
          else
            fail = true;
        }
      }
      if (fail)
        break;
      else {
        for (int i = 0; i < n; i++) {
          if (l[i] != -1) r[i]++;
        }
      }
    }
    std::string t = a[mx_i].substr(l[mx_i], r[mx_i] - l[mx_i] + 1);
    std::string g = b[mx_i].substr(l[mx_i], r[mx_i] - l[mx_i] + 1);
    for (int i = 0; i < n; i++) {
      int u = kmp_search(t, a[i]);
      if (u != -1) {
        for (int j = u; j < u + r[mx_i] - l[mx_i] + 1; j++) a[i][j] = g[j - u];
      }
    }
    bool fail = false;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) fail = true;
    }
    std::cout << (fail ? "NO" : "YES") << '\n';
    if (!fail) {
      std::cout << t << '\n' << g << '\n';
    }
  }
}
