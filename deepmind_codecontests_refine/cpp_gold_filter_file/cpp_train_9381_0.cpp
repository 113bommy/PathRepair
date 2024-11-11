#include <bits/stdc++.h>
using namespace std;
const int power = 26 + 10 + 2;
const int Max = 10005;
char str[Max][12];
int cal(char c) {
  if (isdigit(c))
    return c - '0' + 1;
  else if (c == '.')
    return 11;
  else
    return 12 + c - 'a';
}
unsigned long long Hash(const char* s, int l, int r) {
  unsigned long long hash = 0;
  for (int i = l; i <= r; i++) {
    hash = (hash * power + cal(s[i]));
  }
  return hash;
}
map<unsigned long long, pair<int, int> > Map;
int N, Q;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", str[i]);
    int len = strlen(str[i]);
    set<unsigned long long> s;
    for (int l = 0; l < len; l++) {
      for (int r = l; r < len; r++) {
        unsigned long long hash = Hash(str[i], l, r);
        if (s.find(hash) == s.end()) {
          s.insert(hash);
          if (Map.find(hash) == Map.end())
            Map.insert(make_pair(hash, pair<int, int>(i, 1)));
          else {
            Map[hash].second++;
          }
        }
      }
    }
  }
  scanf("%d", &Q);
  char query[20];
  while (Q--) {
    scanf("%s", query);
    unsigned long long hash = Hash(query, 0, strlen(query) - 1);
    if (Map.find(hash) == Map.end()) {
      printf("0 -\n");
    } else {
      printf("%d %s\n", Map[hash].second, str[Map[hash].first]);
    }
  }
  return 0;
}
