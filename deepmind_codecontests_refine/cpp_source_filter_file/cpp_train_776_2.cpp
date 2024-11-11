#include <bits/stdc++.h>
using namespace std;
int MAX, num[70], idx, memo[int(1e6) + 2][66];
int solve();
void print_soloution(int, int);
void Generate(int);
int main() {
  cin >> MAX;
  Generate(0);
  sort(num, num + idx);
  cout << solve() << endl;
  print_soloution(MAX, idx - 1);
}
int solve() {
  for (int curr = 0; curr <= MAX; curr++) {
    for (int qidx = 0; qidx < idx; qidx++) {
      if (!curr)
        memo[curr][qidx] = 0;
      else if (!qidx)
        memo[curr][qidx] = int(1e8);
      else if (qidx == 1)
        memo[curr][qidx] = curr;
      else {
        int val = num[qidx];
        if (val <= curr)
          memo[curr][qidx] =
              min(memo[curr][qidx - 1], memo[curr - val][qidx] + 1);
        else
          memo[curr][qidx] = memo[curr][qidx - 1];
      }
    }
  }
  return memo[MAX][idx - 1];
}
void print_soloution(int curr, int qidx) {
  if (!curr || !qidx) return;
  int val = num[qidx];
  if (curr >= val && memo[curr][qidx - 1] >= memo[curr - val][qidx]) {
    cout << val << ' ';
    print_soloution(curr - val, qidx);
  } else
    print_soloution(curr, qidx - 1);
}
void Generate(int curr) {
  if (curr > MAX) return;
  num[idx++] = curr;
  if (curr) Generate(curr * 10);
  Generate(curr * 10 + 1);
}
