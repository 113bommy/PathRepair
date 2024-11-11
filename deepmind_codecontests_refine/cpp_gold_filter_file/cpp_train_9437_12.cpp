#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int N = 100;
int frq[N];
int main() {
  string s;
  cin >> s;
  for (int i = 0; s[i]; ++i) {
    frq[s[i] - 'a']++;
  }
  int no = 0;
  vector<int> info;
  for (int i = 0; i < N; ++i) {
    if (frq[i]) {
      ++no;
      info.push_back(frq[i]);
    }
  }
  if (no > 4 || no < 2) {
    puts("No");
    return 0;
  }
  if (no == 2) {
    for (int x : info) {
      if (x == 1) {
        puts("No");
        return 0;
      }
    }
  } else if (no == 3) {
    bool con = false;
    for (int x : info) {
      if (x != 1) {
        con = true;
      }
    }
    if (!con) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}
