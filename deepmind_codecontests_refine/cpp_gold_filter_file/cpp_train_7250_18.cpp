#include <bits/stdc++.h>
using namespace std;
int a[300];
int power[] = {2, 4, 8};
int num = 0;
int n;
vector<string> res;
int recur(int turn) {
  if (a[turn] == n) return 1;
  if (turn == num) return 0;
  for (int i = 0; i <= turn; i++)
    for (long long j = 0; j < ((long long)3); j++)
      if (a[i] * power[j] < 300) {
        a[turn + 1] = a[i] * power[j];
        if (recur(turn + 1)) {
          string str = "lea eax, [0*eax]";
          str[5] += turn + 1;
          str[10] = '0' + power[j];
          str[13] += i;
          res.push_back(str);
          return 1;
        }
      }
  for (int i = 0; i <= turn; i++)
    for (int j = 0; j <= turn; j++)
      if (a[i] + a[j] < 300) {
        a[turn + 1] = a[i] + a[j];
        if (recur(turn + 1)) {
          string str = "lea eax, [eax + eax]";
          str[5] += turn + 1;
          str[11] += i;
          str[17] += j;
          res.push_back(str);
          return 1;
        }
      }
  for (int i = 0; i <= turn; i++)
    for (int j = 0; j <= turn; j++)
      for (long long k = 0; k < ((long long)3); k++)
        if (a[i] + a[j] * power[k] < 300) {
          a[turn + 1] = a[i] + a[j] * power[k];
          if (recur(turn + 1)) {
            string str = "lea eax, [eax + 0*eax]";
            str[5] += turn + 1;
            str[11] += i;
            str[16] = '0' + power[k];
            str[19] += j;
            res.push_back(str);
            return 1;
          }
        }
  return 0;
}
int main() {
  cin >> n;
  a[0] = 1;
  num = 0;
  while (recur(0) == 0) num++;
  reverse(res.begin(), res.end());
  cout << ((long long)res.size()) << endl;
  for (long long i = 0; i < ((long long)((long long)res.size())); i++)
    cout << res[i] << endl;
}
