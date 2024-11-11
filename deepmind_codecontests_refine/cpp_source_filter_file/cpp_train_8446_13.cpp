#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e6 + 10;
map<string, int> ms;
void init() {
  ms["soil"] = 0b010;
  ms["rte"] = 0b100;
  ms["sitini"] = 0b110;
  ms["alail"] = 0b011;
  ms["arte"] = 0b101;
  ms["setini"] = 0b111;
}
int check(string &str) {
  reverse(str.begin(), str.end());
  while (str.size() > 6) str.pop_back();
  while (!str.empty()) {
    if (ms.count(str)) return ms[str];
    str.pop_back();
  }
  return 0;
}
int main() {
  vector<int> v;
  string str;
  init();
  int flag = 0;
  int n = 0;
  while (cin >> str) {
    n++;
    int o = check(str);
    if (o == 0) {
      puts("NO");
      return 0;
    }
    while (!v.empty() && v.back() == o) {
      v.pop_back();
      if (o == 2) {
        puts("NO");
        return 0;
      }
    }
    if (!v.empty() && ((v.back() - o) & 1) == 1) {
      puts("NO");
      return 0;
    }
    v.push_back(o);
    if (o / 2 == 2) {
      flag = 1;
    }
  }
  if (n == 1) {
    puts("YES");
    return 0;
  }
  if (flag == 0 || v.size() > 3) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i < v.size(); i++) {
    if (v[i] != v[i - 1] + 2) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
