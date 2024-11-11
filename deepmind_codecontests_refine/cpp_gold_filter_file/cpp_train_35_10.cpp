#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cnt[100000];
int calc(string str) {
  if (str[2] != '-' || str[5] != '-') return 50000;
  if (str[6] != '2') return 50000;
  if (str[7] != '0') return 50000;
  if (str[8] != '1') return 50000;
  if (str[9] < '3' || str[9] > '5') return -1;
  for (int i = 0; i < 5; i++)
    if (str[i] == '-' && i != 2) return 50000;
  int d = (str[0] - '0') * 10 + str[1] - '0';
  int m = (str[3] - '0') * 10 + str[4] - '0';
  if (m < 1 || m > 12) return 50000;
  if (d < 1 || d > day[m - 1]) return 50000;
  return (str[9] - '3') * 10000 + m * 100 + d;
}
int main() {
  string str;
  cin >> str;
  for (int i = 0; i + 9 < str.length(); i++) cnt[calc(str.substr(i, 10))]++;
  int idx = -1, mx = 0;
  for (int i = 0; i < 30000; i++)
    if (mx < cnt[i]) idx = i, mx = cnt[i];
  printf("%02d-%02d-%d\n", idx % 100, (idx / 100) % 100, 2013 + idx / 10000);
  return 0;
}
