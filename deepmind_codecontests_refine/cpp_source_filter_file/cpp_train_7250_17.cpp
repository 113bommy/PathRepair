#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int mod = 1000000007;
int modpow(int x, int y, int md = mod) {
  if (y == 0) return 1;
  int ret = modpow(x, y >> 1, md);
  ret = (long long)ret * ret % md;
  if (y & 1) ret = (long long)ret * x % md;
  return ret;
}
int n;
vector<string> ans[266];
void check1() {
  if (n == 1) {
    puts("0");
    exit(0);
  }
  ans[2].push_back("lea ebx, [2*eax]");
  ans[4].push_back("lea ebx, [4*eax]");
  ans[8].push_back("lea ebx, [8*eax]");
  ans[3].push_back("lea ebx, [eax + 2*eax]");
  ans[5].push_back("lea ebx, [eax + 4*eax]");
  ans[9].push_back("lea ebx, [eax + 8*eax]");
  if (ans[n].size()) {
    cout << ans[n].size() << endl;
    for (auto s : ans[n]) cout << s << endl;
    exit(0);
  }
}
char orz[2005];
string build(vector<int> cur, int target) {
  char cx = 'a', cy = 'a';
  for (auto x : cur) {
    cy = 'a';
    for (auto y : cur) {
      for (int k = 1; k <= 8; k *= 2) {
        if (x * k == target) {
          sprintf(orz, "lea e%c, [%d*e%cx]", 'a' + (int)cur.size(), k, cx);
          return orz;
        }
        if (x * k + y == target) {
          sprintf(orz, "lea e%cx, [e%cx + %d*e%cx]", 'a' + (int)cur.size(), cy,
                  k, cx);
          return orz;
        }
        if (y * k + x == target) {
          sprintf(orz, "lea e%cx, [e%cx + %d*e%cx]", 'a' + (int)cur.size(), cx,
                  k, cy);
          return orz;
        }
      }
      cy++;
    }
    cx++;
  }
  return "no answer";
}
void check2() {
  for (int v = 2; v < n; v++) {
    if (ans[v].size()) {
      if (build((vector<int>){1, v}, n) != "no answer") {
        ans[n].push_back(ans[v][0]);
        ans[n].push_back(build((vector<int>){1, v}, n));
        break;
      }
    }
  }
  if (ans[n].size()) {
    cout << ans[n].size() << endl;
    for (auto s : ans[n]) cout << s << endl;
    exit(0);
  }
}
void check3() {
  for (int v1 = 2; v1 < n; v1++) {
    if (ans[v1].size() == 1) {
      string step1 = ans[v1][0];
      for (int v2 = v1 + 1; v2 < n; v2++) {
        string step2 = build((vector<int>){1, v1}, v2);
        if (step2 == "no answer") continue;
        string step3 = build((vector<int>){1, v1, v2}, n);
        if (step3 == "no answer") continue;
        cout << 3 << endl;
        cout << step1 << endl;
        cout << step2 << endl;
        cout << step3 << endl;
        exit(0);
      }
    }
  }
}
void check4() {
  for (int v1 = 2; v1 < n; v1++) {
    if (ans[v1].size() == 1) {
      string step1 = ans[v1][0];
      for (int v2 = v1 + 1; v2 < n; v2++) {
        string step2 = build((vector<int>){1, v1}, v2);
        if (step2 == "no answer") continue;
        for (int v3 = v2 + 1; v3 < n; v3++) {
          string step3 = build((vector<int>){1, v1, v2}, v3);
          if (step3 == "no answer") continue;
          string step4 = build((vector<int>){1, v1, v2, v3}, n);
          if (step4 == "no answer") continue;
          cout << 4 << endl;
          cout << step1 << endl;
          cout << step2 << endl;
          cout << step3 << endl;
          cout << step4 << endl;
          exit(0);
        }
      }
    }
  }
}
void check5() {
  for (int v1 = 2; v1 < n; v1++) {
    if (ans[v1].size() == 1) {
      string step1 = ans[v1][0];
      for (int v2 = v1 + 1; v2 < n; v2++) {
        string step2 = build((vector<int>){1, v1}, v2);
        if (step2 == "no answer") continue;
        for (int v3 = v2 + 1; v3 < n; v3++) {
          string step3 = build((vector<int>){1, v1, v2}, v3);
          if (step3 == "no answer") continue;
          for (int v4 = v3 + 1; v4 < n; v4++) {
            string step4 = build((vector<int>){1, v1, v2, v3}, v4);
            if (step4 == "no answer") continue;
            string step5 = build((vector<int>){1, v1, v2, v3, v4}, n);
            if (step5 == "no answer") continue;
            cout << 5 << endl;
            cout << step1 << endl;
            cout << step2 << endl;
            cout << step3 << endl;
            cout << step4 << endl;
            cout << step5 << endl;
            exit(0);
          }
        }
      }
    }
  }
}
int main() {
  cin >> n;
  check1();
  check2();
  check3();
  check4();
  check5();
  return 0;
}
