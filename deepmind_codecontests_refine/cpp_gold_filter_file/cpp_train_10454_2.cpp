#include <bits/stdc++.h>
using namespace std;
inline bool canMake(char first, char last, int len, int cnt) {
  if (len == 2 && first == 'A' && last == 'C') return cnt == 1;
  if (cnt == 0) return true;
  if (cnt * 2 <= len - 2) return true;
  if (cnt * 2 == len - 1 && (first == 'A' || last == 'C')) return true;
  if (cnt * 2 == len && first == 'A' && last == 'C') return true;
  return false;
}
void printString(char first, char last, int len, int cnt) {
  char res[512];
  int pos;
  res[0] = first;
  if (first == 'A' && cnt > 0)
    pos = 0;
  else
    pos = 1;
  for (int i = 0; i < (int)(cnt); ++i) {
    res[pos] = 'A';
    res[pos + 1] = 'C';
    pos += 2;
  }
  while (pos < len - 1) res[pos++] = 'B';
  res[len - 1] = last;
  res[len] = 0;
  puts(res);
}
int main() {
  int k, x, n, m;
  cin >> k >> x >> n >> m;
  bool found = false;
  for (char a1 = 'A'; a1 <= 'C'; ++a1) {
    for (char b1 = 'A'; b1 <= 'C'; ++b1) {
      for (char a2 = 'A'; a2 <= 'C'; ++a2) {
        for (char b2 = 'A'; b2 <= 'C'; ++b2) {
          for (int n1 = 0; n1 <= n / 2; ++n1) {
            for (int n2 = 0; n2 <= m / 2; ++n2) {
              long long res = 0, cnt1 = n1, cnt2 = n2;
              char start1 = a1, start2 = b1, end1 = a2, end2 = b2, tmp;
              for (int nk = 3; nk <= k; ++nk) {
                res = cnt1 + cnt2;
                if (end1 == 'A' && start2 == 'C') ++res;
                if (k == nk && res == x) {
                  if (n == 1 && a1 != a2) continue;
                  if (m == 1 && b1 != b2) continue;
                  if (!canMake(a1, a2, n, n1)) continue;
                  if (!canMake(b1, b2, m, n2)) continue;
                  printString(a1, a2, n, n1);
                  printString(b1, b2, m, n2);
                  found = true;
                  goto out;
                }
                cnt1 = cnt2;
                cnt2 = res;
                tmp = start1;
                start1 = start2;
                end1 = end2;
                start2 = tmp;
                end2 = end2;
                if (res > x) break;
              }
            }
          }
        }
      }
    }
  }
out:;
  if (!found) puts("Happy new year!");
  return 0;
}
