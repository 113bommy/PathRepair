#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
int main() {
  long long i, n, j, a;
  char *s1 = new char[2000], *s2 = new char[2000];
  memset(s1, 0, 2000);
  memset(s2, 0, 2000);
  cin >> n;
  cin >> s1;
  cin >> s2;
  long long sl1 = strlen(s1), sl2 = strlen(s2), nok = 1;
  for (i = 1; i < 2000000; ++i)
    if (i % sl1 == 0 && i % sl2 == 0) {
      nok = i;
      break;
    }
  long long r1 = 0, r2 = 0;
  if (nok > n) nok = n;
  for (i = 0; i < nok; ++i) {
    if (s1[i % sl1] == 'R' && s2[i % sl2] == 'S') ++r2;
    if (s1[i % sl1] == 'R' && s2[i % sl2] == 'P') ++r1;
    if (s1[i % sl1] == 'S' && s2[i % sl2] == 'R') ++r1;
    if (s1[i % sl1] == 'S' && s2[i % sl2] == 'P') ++r2;
    if (s1[i % sl1] == 'P' && s2[i % sl2] == 'S') ++r1;
    if (s1[i % sl1] == 'P' && s2[i % sl2] == 'R') ++r2;
  }
  long long nroun = n / nok;
  r1 *= nroun;
  r2 *= nroun;
  nroun *= nok;
  j = n % nok;
  for (i = 0; i < j; ++i) {
    if (s1[(i + nroun) % sl1] == 'R' && s2[(i + nroun) % sl2] == 'S') ++r2;
    if (s1[(i + nroun) % sl1] == 'R' && s2[(i + nroun) % sl2] == 'P') ++r1;
    if (s1[(i + nroun) % sl1] == 'S' && s2[(i + nroun) % sl2] == 'R') ++r1;
    if (s1[(i + nroun) % sl1] == 'S' && s2[(i + nroun) % sl2] == 'P') ++r2;
    if (s1[(i + nroun) % sl1] == 'P' && s2[(i + nroun) % sl2] == 'S') ++r1;
    if (s1[(i + nroun) % sl1] == 'P' && s2[(i + nroun) % sl2] == 'R') ++r2;
  }
  cout << r1 << " " << r2;
  return 0;
}
