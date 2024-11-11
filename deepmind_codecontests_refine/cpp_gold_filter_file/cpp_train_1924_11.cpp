#include <bits/stdc++.h>
using namespace std;
int n, cev[1505], d[1505];
long long int say, say2;
long long int m;
string a;
void fon1() {
  for (int i1 = 0; i1 < n; i1++)
    for (int j1 = i1; j1 < n; j1++) {
      string t = a, nw;
      for (int i = i1; i <= (i1 + j1) / 2; i++) swap(t[i], t[j1 - (i - i1)]);
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
          if (t[i] > t[j]) say++;
      say2++;
    }
}
void fon2() {
  for (int i1 = 0; i1 < n; i1++)
    for (int j1 = i1; j1 < n; j1++)
      for (int i2 = 0; i2 < n; i2++)
        for (int j2 = i2; j2 < n; j2++) {
          string t = a, nw;
          for (int i = i1; i <= (i1 + j1) / 2; i++)
            swap(t[i], t[j1 - (i - i1)]);
          for (int i = i2; i <= (i2 + j2) / 2; i++)
            swap(t[i], t[j2 - (i - i2)]);
          for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
              if (t[i] > t[j]) say++;
          say2++;
        }
}
void fon3() {
  for (int i1 = 0; i1 < n; i1++)
    for (int j1 = i1; j1 < n; j1++)
      for (int i2 = 0; i2 < n; i2++)
        for (int j2 = i2; j2 < n; j2++)
          for (int i3 = 0; i3 < n; i3++)
            for (int j3 = i3; j3 < n; j3++) {
              string t = a, nw;
              for (int i = i1; i <= (i1 + j1) / 2; i++)
                swap(t[i], t[j1 - (i - i1)]);
              for (int i = i2; i <= (i2 + j2) / 2; i++)
                swap(t[i], t[j2 - (i - i2)]);
              for (int i = i3; i <= (i3 + j3) / 2; i++)
                swap(t[i], t[j3 - (i - i3)]);
              for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                  if (t[i] > t[j]) say++;
              say2++;
            }
}
void fon4() {
  for (int i1 = 0; i1 < n; i1++)
    for (int j1 = i1; j1 < n; j1++)
      for (int i2 = 0; i2 < n; i2++)
        for (int j2 = i2; j2 < n; j2++)
          for (int i3 = 0; i3 < n; i3++)
            for (int j3 = i3; j3 < n; j3++)
              for (int i4 = 0; i4 < n; i4++)
                for (int j4 = i4; j4 < n; j4++) {
                  string t = a, nw;
                  for (int i = i1; i <= (i1 + j1) / 2; i++)
                    swap(t[i], t[j1 - (i - i1)]);
                  for (int i = i2; i <= (i2 + j2) / 2; i++)
                    swap(t[i], t[j2 - (i - i2)]);
                  for (int i = i3; i <= (i3 + j3) / 2; i++)
                    swap(t[i], t[j3 - (i - i3)]);
                  for (int i = i4; i <= (i4 + j4) / 2; i++)
                    swap(t[i], t[j4 - (i - i4)]);
                  for (int i = 0; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                      if (t[i] > t[j]) say++;
                  say2++;
                }
}
int main() {
  scanf("%d %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    a.push_back(d[i]);
  }
  if (m == 1) fon1();
  if (m == 2) fon2();
  if (m == 3) fon3();
  if (m == 4) fon4();
  printf("%.15lf", (double)say / say2);
}
