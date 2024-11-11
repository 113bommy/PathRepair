#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, pos[N], tt;
vector<pair<int, int> > way_4 = {{0, 1}, {0, 2}, {1, 3},
                                 {0, 3}, {1, 2}, {2, 3}};
vector<pair<int, int> > way_5 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4},
                                 {2, 4}, {0, 4}, {2, 3}, {1, 3}, {3, 4}};
vector<pair<int, int> > way_44 = {
    {0, 4}, {0, 5}, {0, 6}, {1, 4}, {1, 7}, {0, 7}, {1, 6}, {2, 4},
    {3, 5}, {2, 5}, {1, 5}, {2, 6}, {3, 4}, {3, 7}, {2, 7}, {3, 6}};
vector<pair<int, int> > way_45 = {
    {0, 8}, {0, 4}, {4, 8}, {0, 5}, {0, 6}, {1, 4}, {1, 7}, {0, 7},
    {1, 6}, {2, 4}, {3, 5}, {2, 5}, {1, 8}, {1, 5}, {5, 8}, {2, 8},
    {2, 6}, {6, 8}, {3, 4}, {3, 8}, {3, 7}, {7, 8}, {2, 7}, {3, 6}};
vector<pair<int, int> > ans;
void work1(int x, vector<pair<int, int> > &tmp) {
  for (auto t : tmp) ans.push_back(make_pair(t.first + x, t.second + x));
}
int getid(int x, int y, int t) {
  if (t < 4) return x + t;
  if (4 <= t && t < 8) return y + t - 4;
  return n - 1;
}
void work2(int x, int y, vector<pair<int, int> > &tmp) {
  for (auto t : tmp)
    ans.push_back(make_pair(getid(x, y, t.first), getid(x, y, t.second)));
}
int main() {
  cin >> n;
  if (n % 4 == 2 || n % 4 == 3) return puts("NO"), 0;
  puts("YES");
  if (n == 1) return 0;
  for (int i = 0; i < n; i += 4) {
    pos[++tt] = i;
    if (i + 5 == n) break;
  }
  if (n % 4 == 0) {
    for (int i = 1; i <= tt; i++) work1(pos[i], way_4);
    for (int i = 1; i <= tt; i++)
      for (int j = i + 1; j <= tt; j++) work1(pos[i], way_44);
  } else if (tt & 1) {
    for (int i = 1; i < tt; i++) work1(pos[i], way_4);
    work1(pos[tt], way_5);
    for (int i = 1; i <= tt; i++)
      for (int j = i + 1; j <= tt; j++)
        if (j == i + 1 && (i & 1))
          work2(pos[i], pos[j], way_45);
        else
          work2(pos[i], pos[j], way_44);
  } else {
    for (int i = 1; i <= tt; i++) work1(pos[i], way_4);
    for (int i = 1; i <= tt; i++)
      for (int j = i + 1; j <= tt; j++)
        if (j == i + 1 && (i & 1))
          work2(pos[i], pos[j], way_45);
        else
          work2(pos[i], pos[j], way_44);
  }
  for (auto t : ans) cout << t.first + 1 << ' ' << t.second + 1 << '\n';
  return 0;
}
