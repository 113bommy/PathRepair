#include <bits/stdc++.h>
using namespace std;
int main() {
  int N[5], T[5];
  unsigned int NS, NM, NL, NXL, NXXL;
  unsigned int K, i;
  string S[5];
  scanf("%u%u%u%u%u%u", &NS, &NM, &NL, &NXL, &NXXL, &K);
  N[0] = NS;
  N[1] = NM;
  N[2] = NL;
  N[3] = NXL;
  N[4] = NXXL;
  T[0] = 0;
  T[1] = 1;
  T[2] = 2;
  T[3] = 3;
  T[4] = 4;
  S[0] = "S";
  S[1] = "M";
  S[2] = "L";
  S[3] = "XL";
  S[4] = "XXL";
  for (i = 0; i < K; i++) {
    char cstr[5];
    scanf("%s", cstr);
    string str(cstr);
    int k;
    if (str == S[0])
      k = 0;
    else if (str == S[1])
      k = 1;
    else if (str == S[2])
      k = 2;
    else if (str == S[3])
      k = 3;
    else if (str == S[4])
      k = 4;
    int l = 1;
    while (N[k] == 0) {
      if (k + l < 5 && N[k + l] != 0)
        k = k + l;
      else if (k - l >= 0 && N[k - l] != 0)
        k = k - l;
      l++;
    }
    N[k]--;
    printf("%s\n", S[k].c_str());
  }
  return 0;
}
