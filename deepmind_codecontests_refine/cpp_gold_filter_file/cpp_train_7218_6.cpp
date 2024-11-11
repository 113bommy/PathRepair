#include <bits/stdc++.h>
using namespace std;
long long labs(long long a) { return a < 0 ? (-a) : a; }
void FAIL() {
  cout << "Error occurred" << endl;
  exit(0);
}
struct Pair {
  int parent;
  int first;
  int second;
  int cnt;
  Pair(int p) : parent(p), cnt(0) {}
  Pair(int p, int c) : parent(p), cnt(c) {}
  bool IsInt() { return cnt < 0; }
  void Add(int i) {
    if (cnt == 0)
      first = i;
    else if (cnt == 1)
      second = i;
    else
      FAIL();
    cnt++;
  }
};
vector<Pair> pairs;
int cur = 0;
void Cout(int i) {
  if (pairs[i].IsInt()) {
    printf("int");
  } else {
    printf("pair<");
    Cout(pairs[i].first);
    printf(",");
    Cout(pairs[i].second);
    printf(">");
  }
}
int main() {
  string s;
  string ans = "";
  int n;
  cin >> n;
  pairs.reserve(2 * n);
  pairs.push_back(Pair(-1));
  while (cin >> s) {
    if (s == "pair") {
      pairs[cur].Add(pairs.size());
      pairs.push_back(Pair(cur));
      cur = pairs.size() - 1;
    } else {
      pairs[cur].Add(pairs.size());
      pairs.push_back(Pair(cur, -1));
      while (pairs[cur].cnt == 2) {
        if (cur == 0) FAIL();
        cur = pairs[cur].parent;
      }
    }
  }
  if (cur != 0 || pairs[cur].cnt != 1) {
    FAIL();
  }
  Cout(pairs[0].first);
  cout << endl;
  return 0;
}
