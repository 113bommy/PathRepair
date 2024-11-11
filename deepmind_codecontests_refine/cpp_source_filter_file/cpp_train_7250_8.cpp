#include <bits/stdc++.h>
using namespace std;
int val[26];
int n;
int deep;
char ans[200][200];
void print() {
  cout << deep << endl;
  for (int i = 1; i <= deep; i++) puts(ans[i]);
  exit(0);
}
void perebor(int pos) {
  if (pos == deep + 1) {
    if (val[pos - 1] == n) print();
    return;
  }
  if (pos > 1 && val[pos - 2] > val[pos - 1]) return;
  if (val[pos - 1] > n) return;
  for (int i = 0; i < pos; i++) {
    sprintf(ans[pos], "lea e%cx [4*e%cx]", char('a' + pos), char(i + 'a'));
    val[pos] = 4 * val[i];
    perebor(pos + 1);
    sprintf(ans[pos], "lea e%cx [8*e%cx]", char('a' + pos), char(i + 'a'));
    val[pos] = 8 * val[i];
    perebor(pos + 1);
  }
  for (int i = 0; i < pos; i++)
    for (int j = 0; j < pos; j++)
      for (int k = 1; k <= 8; k <<= 1) {
        sprintf(ans[pos], "lea e%cx [e%cx + %d*e%cx]", char(pos + 'a'),
                char(i + 'a'), k, char(j + 'a'));
        val[pos] = val[i] + k * val[j];
        perebor(pos + 1);
      }
}
int main() {
  cin >> n;
  for (deep = 0;; ++deep) {
    val[0] = 1;
    perebor(1);
  }
  return 0;
}
