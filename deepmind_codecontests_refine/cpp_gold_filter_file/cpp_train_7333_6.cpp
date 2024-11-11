#include <bits/stdc++.h>
using namespace std;
long long next_int, sign;
char in_char;
inline long long rd() {
  in_char = ' ';
  sign = 1;
  while ((in_char < '0') || (in_char > '9')) {
    in_char = getchar();
    if (in_char == '-') {
      sign = -1;
    }
  }
  next_int = 0;
  while ((in_char >= '0') && (in_char <= '9')) {
    next_int *= 10;
    next_int += in_char - 48;
    in_char = getchar();
  }
  return next_int * sign;
}
int till = 100000;
vector<vector<int> > v;
vector<long long> divi;
int ct = 0;
void dfs(long long i, long long k) {
  if (ct == till) return;
  if (i == 0 || k == 0) {
    cout << divi[i] << " ";
    ++ct;
    return;
  }
  for (int j = 0; j < ((int)(v[i].size())); j++) dfs(v[i][j], k - 1);
}
int main() {
  long long x, k;
  x = rd();
  k = rd();
  for (long long i = 1; i <= x / i; i++)
    if (x % i == 0) {
      divi.push_back(i);
      if ((i * i) != x) divi.push_back(x / i);
    }
  sort(divi.begin(), divi.end());
  v = vector<vector<int> >(((int)(divi.size())), vector<int>());
  for (int i = 0; i < ((int)(divi.size())); i++) {
    for (int j = 0; j <= i; j++)
      if (divi[i] % divi[j] == 0) v[i].push_back(j);
  }
  if (k > till) k = till;
  dfs(((int)(divi.size())) - 1, k);
  cout << endl;
}
