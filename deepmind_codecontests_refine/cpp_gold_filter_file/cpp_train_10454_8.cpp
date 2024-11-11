#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
int k, x, n, m;
bool solve(char L1, char R1, long long c1, char L2, char R2, long long c2) {
  long long c;
  int i;
  for (i = 3; i <= k; i++) {
    char L3 = L1;
    char R3 = R2;
    c = c1 + c2 + int(R1 == 'A' && L2 == 'C');
    if (c > x) break;
    L1 = L2;
    R1 = R2;
    c1 = c2;
    L2 = L3;
    R2 = R3;
    c2 = c;
  }
  return i >= k && c == x;
}
string gen(char L, char R, int c, int n) {
  char s[] = "AC";
  do {
    string res(n, 'B');
    res[0] = L;
    res[n - 1] = R;
    int cnt = 0;
    for (int i = 1; i < n - 1 && cnt < c; i++) {
      res[i] = s[i & 1];
      cnt += res[i] == 'C' && res[i - 1] == 'A';
    }
    cnt += n > 1 && res[n - 1] == 'C' && res[n - 2] == 'A';
    if (cnt == c && res[0] == L && res[n - 1] == R) return res;
  } while (next_permutation(s, s + 2));
  return "";
}
int main() {
  cin >> k >> x >> n >> m;
  for (int a1 = 'A'; a1 <= 'C'; a1++) {
    for (int b1 = 'A'; b1 <= 'C'; b1++) {
      for (int a2 = 'A'; a2 <= 'C'; a2++) {
        for (int b2 = 'A'; b2 <= 'C'; b2++) {
          for (int c1 = n / 2; c1 >= 0; c1--) {
            string s1 = gen(a1, b1, c1, n);
            if (s1 != "") {
              for (int c2 = m / 2; c2 >= 0; c2--) {
                string s2 = gen(a2, b2, c2, m);
                if (s2 != "") {
                  if (solve(a1, b1, c1, a2, b2, c2)) {
                    cout << s1 << endl;
                    cout << s2 << endl;
                    return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  puts("Happy new year!");
}
