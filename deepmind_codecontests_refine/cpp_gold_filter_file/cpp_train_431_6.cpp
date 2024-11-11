#include <bits/stdc++.h>
using namespace std;
template <typename IntType>
void read(IntType& val) {
  val = 0;
  int c;
  bool inv = false;
  while (!isdigit(c = getchar()))
    if (c == '-') inv = true;
  do {
    val = (val << 1) + (val << 3) + c - '0';
  } while (isdigit(c = getchar()));
  if (inv) val = -val;
}
template <>
void read<string>(string& str) {
  str.clear();
  int c;
  while (iscntrl(c = getchar()) || c == ' ' || c == '\t')
    ;
  do {
    str.push_back(c);
  } while (!(iscntrl(c = getchar()) || c == ' ' || c == '\t'));
}
const int MaxN = 3 * 1e5 + 10, MaxM = 5e5 + 10;
int t;
int n, m;
int u[MaxM], v[MaxM];
bool taken[MaxN];
vector<int> ts;
int main(int argc, char* argv[]) {
  read(t);
  while (t--) {
    read(n);
    read(m);
    for (int i = (1); i <= (m); ++i) {
      read(u[i]);
      read(v[i]);
    }
    for (int i = (1); i <= (3 * n); ++i) taken[i] = false;
    ts.clear();
    for (int i = (1); i <= (m); ++i) {
      if (!taken[u[i]] && !taken[v[i]]) {
        taken[u[i]] = taken[v[i]] = true;
        ts.push_back(i);
      }
    }
    if (ts.size() >= n) {
      printf("Matching\n");
      printf("%d", ts[0]);
      for (int i = (1); i <= (n - 1); ++i) printf(" %d", ts[i]);
      printf("\n");
    } else {
      printf("IndSet\n");
      bool first = true;
      int cnt = 0;
      for (int i = (1); i <= (3 * n); ++i) {
        if (!taken[i]) {
          cnt++;
          if (first) {
            first = false;
            printf("%d", i);
          } else
            printf(" %d", i);
        }
        if (cnt >= n) break;
      }
      printf("\n");
    }
  }
  return 0;
}
