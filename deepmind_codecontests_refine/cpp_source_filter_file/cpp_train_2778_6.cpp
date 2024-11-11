#include <bits/stdc++.h>
using namespace std;
long long n;
long long d[10];
long long frac[20];
std::set<string> isExists;
void init() {
  frac[0] = 0;
  frac[1] = 1;
  for (int i = 2; i <= 19; i++) {
    frac[i] = frac[i - 1] * i;
  }
}
long long calcNum(long long d[], int depth) {
  long long count = 0;
  long long section = 0;
  for (int i = 1; i <= 9; i++) {
    if (d[i] == 0) continue;
    d[i]--;
    section = frac[depth - 1];
    for (int j = 0; j <= 9; j++) {
      if (d[j] != 0) section = section / frac[d[j]];
    }
    d[i]++;
    count = count + section;
  }
  return count;
}
string makeString(long long d[]) {
  string s = "";
  char ch;
  for (int i = 0; i <= 9; i++) {
    ch = d[i] + '0';
    s = s + ch;
  }
  return s;
}
long long total;
void doSearch(int depth) {
  total = total + calcNum(d, depth);
  for (int i = 0; i <= 9; i++) {
    if (d[i] == 0) continue;
    if (d[i] == 1) continue;
    d[i]--;
    string newS = makeString(d);
    if (isExists.find(newS) == isExists.end()) {
      isExists.insert(newS);
      doSearch(depth - 1);
    }
    d[i]++;
  }
}
int main() {
  init();
  scanf("%I64d", &n);
  long long depth = 0;
  long long t = n;
  while (t > 0) {
    d[t % 10]++;
    t = t / 10;
    depth++;
  }
  total = 0;
  total = total + calcNum(d, depth);
  for (int i = 0; i <= 9; i++) {
    if (d[i] == 0) continue;
    if (d[i] == 1) continue;
    d[i]--;
    string newS = makeString(d);
    if (isExists.find(newS) == isExists.end()) {
      isExists.insert(newS);
      doSearch(depth - 1);
    }
    d[i]++;
  }
  printf("%I64d\n", total);
  return 0;
}
