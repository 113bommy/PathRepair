#include <bits/stdc++.h>
using namespace std;
const int seed = 514;
mt19937 rng(seed);
int randint(int lb, int ub) {
  return uniform_int_distribution<int>(lb, ub)(rng);
}
const int MAXN = 1e4 + 100;
const string Name[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
int get_id(char c) {
  for (int i = 0; i < 4; i++)
    if (c == Name[i][0]) return i;
  assert(c == '?');
  return -1;
}
int suf[4][MAXN];
const int GO = 1000;
int main() {
  for (int i = 1; i < 4; i++) assert(Name[i - 1] < Name[i]);
  int n;
  string second;
  cin >> n >> second;
  for (int t = 0; t < 4; t++)
    for (int i = n - 1; i >= 0; i--)
      suf[t][i] = suf[t][i + 1] + (get_id(second[i]) == t);
  for (int t = 0; t < 4; t++) {
    for (int pp = 0; pp < GO; pp++) {
      int sum[4] = {};
      for (int i = 0; i < n; i++) {
        int id = get_id(second[i]);
        if (id >= 0) {
          sum[id]++;
        } else {
          int sml_cur = MAXN;
          for (int j = 0; j < 4; j++) sml_cur = min(sml_cur, sum[j]);
          vector<int> ch;
          for (int j = 0; j < 4; j++)
            if (sml_cur == sum[j]) ch.push_back(j);
          sum[ch[randint(0, ((int)(ch).size()) - 1)]]++;
        }
      }
      int sml_cur = MAXN;
      for (int j = 0; j < 4; j++) sml_cur = min(sml_cur, sum[j]);
      if (sum[t] == sml_cur) {
        cout << Name[t] << endl;
        break;
      }
    }
  }
  return 0;
}
