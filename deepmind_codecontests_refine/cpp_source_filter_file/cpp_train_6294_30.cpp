#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 1000000000;
bool comp(const pair<char, int> &a, const pair<char, int> &b) {
  return a.second < b.second;
}
int main() {
  pair<char, int> p[3];
  p[0].first = 'A', p[0].second = 0;
  p[1].first = 'B', p[0].second = 0;
  p[2].first = 'C', p[0].second = 0;
  string temp;
  for (int i = 0; i < 3; ++i) {
    cin >> temp;
    if (temp[1] == '<') {
      --p[temp[0] - 'A'].second;
      ++p[temp[2] - 'A'].second;
    } else {
      ++p[temp[0] - 'A'].second;
      --p[temp[2] - 'A'].second;
    }
  }
  bool flag = true;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (j != i && p[i].second == p[j].second) {
        flag = false;
        printf("Imposibble\n");
        break;
      }
    }
    if (!flag) break;
  }
  if (flag) {
    sort(p, p + 3, comp);
    for (int i = 0; i < 3; ++i) putchar(p[i].first);
    putchar('\n');
  }
}
