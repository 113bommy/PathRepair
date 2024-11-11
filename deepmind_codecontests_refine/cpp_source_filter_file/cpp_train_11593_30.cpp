#include <bits/stdc++.h>
using namespace std;
map<string, int> tj, si;
map<int, string> is;
struct ac {
  int m1, m2, m3;
  int hao;
} so[5];
struct c {
  int m11, m22, m33;
  int hao2;
} cop[5];
int cmp(c x, c y) {
  if (x.m11 != y.m11) {
    return x.m11 > y.m11;
  } else if (x.m22 != y.m22) {
    return x.m22 > y.m22;
  } else if (x.m33 != y.m33) {
    return x.m33 > y.m33;
  } else
    return is[x.hao2] < is[y.hao2];
}
int main() {
  string s1[6], s2[6];
  int x1[6], x2[6], sis = 0, minn[2] = {999999999, 999999999}, ssm, mms;
  int jin[5] = {0}, lou[5] = {0}, fen[5] = {0};
  for (int i = 1; i <= 5; i++) {
    char ch;
    cin >> s1[i] >> s2[i] >> x1[i] >> ch >> x2[i];
    tj[s1[i]]++;
    tj[s2[i]]++;
    if (si[s1[i]] == 0) {
      sis++;
      si[s1[i]] = sis;
      is[sis] = s1[i];
    }
    if (si[s2[i]] == 0) {
      sis++;
      si[s2[i]] = sis;
      is[sis] = s2[i];
    }
    jin[si[s1[i]]] += x1[i], jin[si[s2[i]]] += x2[i];
    lou[si[s1[i]]] += x2[i], lou[si[s2[i]]] += x1[i];
    if (x1[i] > x2[i]) fen[si[s1[i]]] += 3;
    if (x1[i] == x2[i]) fen[si[s1[i]]]++, fen[si[s2[i]]]++;
    if (x1[i] < x2[i]) fen[si[s2[i]]] += 3;
  }
  int sum = 0;
  int b[3] = {0};
  for (int i = 1; i <= 4; i++) {
    if (tj[is[i]] == 2) {
      sum++;
      b[sum] = i;
      if (is[i] == "BERLAND" && sum == 2) {
        swap(b[1], b[2]);
      }
    }
    so[i].m1 = fen[i];
    so[i].m2 = jin[i] - lou[i];
    so[i].m3 = jin[i];
    so[i].hao = i;
  }
  for (int i = 0; i <= 100; i++)
    for (int k = 0; k <= i; k++) {
      for (int j = 1; j <= 4; j++) {
        cop[j].m11 = so[j].m1;
        cop[j].m22 = so[j].m2;
        cop[j].m33 = so[j].m3;
        cop[j].hao2 = so[j].hao;
      }
      cop[b[1]].m22 = cop[b[1]].m22 + i - k, cop[b[1]].m33 += i;
      cop[b[2]].m22 = cop[b[2]].m22 - i + k, cop[b[2]].m33 += k;
      if (i == k)
        cop[b[1]].m11++, cop[b[2]].m11++;
      else
        cop[b[1]].m11 += 3;
      sort(cop + 1, cop + 5, cmp);
      for (int j = 1; j <= 2; j++) {
        if (is[cop[j].hao2] == "BERLAND") {
          if (i - k < minn[0]) {
            minn[0] = i - k;
            minn[1] = k;
            ssm = i;
            mms = k;
          } else if (i - k == minn[0] && k < minn[1]) {
            minn[1] = k;
            ssm = i;
            mms = k;
          }
        }
      }
    }
  if (minn[0] != 999999999)
    cout << ssm << ':' << mms;
  else
    cout << "IMPOSSIBLE";
  return 0;
}
