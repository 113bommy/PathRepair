#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int equiv[10];
void fuck(vector<int> v) {
  printf("meet");
  for (int i = 0; i < v.size(); i++) printf(" %d", v[i]);
  printf("\n");
  fflush(stdout);
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) equiv[s[j] - '0'] = i;
  }
}
bool meet(int x, int y) { return equiv[x] == equiv[y]; }
int main() {
  while (true) {
    fuck({0, 1});
    fuck({1});
    if (meet(0, 1)) break;
  }
  while (true) {
    fuck({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    if (meet(0, 2)) break;
  }
  puts("done");
  fflush(stdout);
}
