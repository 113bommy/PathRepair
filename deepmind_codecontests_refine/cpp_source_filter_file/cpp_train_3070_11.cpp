#include <bits/stdc++.h>
inline long long Power(int b, int p) {
  long long r = 1;
  for (int i = 1; i <= p; i++) r *= b;
  return r;
}
using namespace std;
template <typename T>
void print(T const& c) {
  typename T::const_iterator s;
  typename T::const_iterator e(c.end());
  for (s = c.begin(); s != e; ++s) {
    cout << *s << ' ';
  }
  cout << endl;
}
char s[1000000];
char t[1000000];
char p[1000000];
int main() {
  scanf("%s %s", s, t);
  int n = (int)strlen(s);
  vector<int> diffIndex;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i])
      diffIndex.push_back(i);
    else
      p[i] = s[i];
  }
  if (diffIndex.size() % 2 == 1)
    printf("Impossible\n");
  else {
    for (size_t i = 0; i < diffIndex.size(); i++) {
      if (i % 2) {
        p[diffIndex[i]] = s[diffIndex[i]];
      } else {
        p[diffIndex[i]] = t[diffIndex[i]];
      }
    }
    p[n] = 0;
    printf("%s\n", p);
  }
  return 0;
}
