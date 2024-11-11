#include <bits/stdc++.h>
using namespace std;
char s[200001], sir[200001], r[200001];
int main() {
  int n, ind1, ind2, vec[400] = {0}, i, nr = 0;
  char x;
  fgets(s, 200001, stdin);
  n = strlen(s);
  n--;
  for (i = 0; i < n; i++) {
    vec[(int)(s[i])]++;
  }
  for (i = 'a'; i <= 'z'; i++) {
    if (vec[i] % 2 == 1) {
      r[nr] = i;
      nr++;
    }
  }
  r[nr] = NULL;
  ind1 = 0;
  ind2 = nr - 1;
  while (ind1 < ind2) {
    vec[(int)(r[ind1])]++;
    vec[(int)(r[ind2])]--;
    ind1++;
    ind2--;
  }
  ind1 = 0;
  ind2 = n - 1;
  nr = 0;
  for (i = 'a'; i <= 'z'; i++) {
    if (vec[i] % 2 == 1) {
      x = i;
      vec[i]--;
    }
  }
  for (i = 'a'; i <= 'z'; i++) {
    while (vec[i] != 0) {
      sir[ind1] = i;
      sir[ind2] = i;
      vec[i] = vec[i] - 2;
      ind1++;
      ind2--;
    }
  }
  if (n % 2 == 1) {
    sir[ind1] = x;
  }
  sir[n] = NULL;
  cout << sir << endl;
  return 0;
}
