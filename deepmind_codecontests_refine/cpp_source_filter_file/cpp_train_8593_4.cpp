#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > N;
void convert(char S[], long long a) {
  int i;
  S[18] = 0;
  for (i = 0; i < 18; i++) {
    S[i] = (a % 10) & 1;
    a /= 10;
  }
}
int main() {
  int t, i, src = 0, l, ptr;
  char S[20];
  long long a;
  N.push_back(make_pair(-1, -1));
  scanf("%d", &t);
  while (t--) {
    scanf("%s", S);
    if (S[0] == '+') {
      scanf("%l64d", &a);
      convert(S, a);
      ptr = src;
      for (i = 0; i < 18; i++) {
        if (S[i] == 0) {
          if (N[ptr].first == -1) {
            N[ptr].first = N.size();
            N.push_back(make_pair(-1, -1));
          }
          ptr = N[ptr].first;
        } else {
          if (N[ptr].second == -1) {
            N[ptr].second = N.size();
            N.push_back(make_pair(-1, -1));
          }
          ptr = N[ptr].second;
        }
      }
      N[ptr].first = N[ptr].first == -1 ? 1 : N[ptr].first + 1;
    } else if (S[0] == '-') {
      scanf("%l64d", &a);
      convert(S, a);
      ptr = src;
      for (i = 0; i < 18; i++) {
        if (S[i] == 0) {
          ptr = N[ptr].first;
        } else {
          ptr = N[ptr].second;
        }
      }
      N[ptr].first--;
    } else {
      scanf("%s", S);
      ptr = src;
      l = strlen(S);
      for (i = 0; i < 18 && S[i] && ptr != -1; i++) {
        if (S[l - 1 - i] == '0') {
          ptr = N[ptr].first;
        } else {
          ptr = N[ptr].second;
        }
      }
      for (; i < 18 && ptr != -1; i++) ptr = N[ptr].first;
      printf("%d\n", ptr == -1 ? 0 : N[ptr].first);
    }
  }
  return 0;
}
