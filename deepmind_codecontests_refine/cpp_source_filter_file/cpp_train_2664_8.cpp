#include <bits/stdc++.h>
using namespace std;
char getchar(int val) {
  if (val == 0) return 'R';
  if (val == 1) return 'O';
  if (val == 2) return 'Y';
  if (val == 3) return 'G';
  if (val == 4) return 'B';
  if (val == 5) return 'I';
  return 'V';
}
bool check(vector<int> b, int kol) {
  vector<int> cc(4);
  for (int i = 0; i < ((int)cc.size()); i++) cc[i] = i + 3;
  for (int i = 0; i < kol; i++) cc.push_back(b[i]);
  for (int i = 0; i < 4; i++) cc.push_back(i);
  for (int i = 0; i < kol; i++) {
    int ind = i + 4;
    for (int j = ind - 3; j <= ind + 3; j++) {
      if (ind == j) continue;
      if (cc[ind] == cc[j]) return false;
    }
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  vector<int> answer(7 * (n / 7));
  int vv = n % 7;
  int to = 7 * (n / 7);
  for (int i = 0; i < to; i++) answer[i] = i % to;
  if (to == n) {
    for (int i = 0; i < ((int)answer.size()); i++) cout << getchar(answer[i]);
    return 0;
  }
  vector<int> perm(7);
  for (int i = 0; i < 7; i++) perm[i] = i;
  while (next_permutation(perm.begin(), perm.end())) {
    if (check(perm, vv)) {
      for (int i = 0; i < vv; i++) answer.push_back(perm[i]);
      for (int i = 0; i < ((int)answer.size()); i++) cout << getchar(answer[i]);
      return 0;
    }
  }
  return 0;
}
