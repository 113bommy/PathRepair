#include <bits/stdc++.h>
using namespace std;
int n, m, t;
vector<pair<int, int> > event[100005];
int id[20005];
char format[10];
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%s", format);
    int hour = (format[0] - '0') * 10 + (format[1] - '0');
    int minute = (format[3] - '0') * 10 + (format[4] - '0');
    int second = (format[6] - '0') * 10 + (format[7] - '0');
    int left = hour * 60 * 60 + minute * 60 + second;
    int right = left + t - 1;
    event[left].push_back(make_pair(i, 1));
    event[right].push_back(make_pair(i, -1));
  }
  int online = 0, user = 0, max_online = 0;
  for (int i = 0; i <= 86400; ++i) {
    for (int j = 0; j < event[i].size(); ++j) {
      if (event[i][j].second == -1) continue;
      online++;
      id[event[i][j].first] = ++user;
      if (online > m) {
        id[event[i][j].first] = --user;
        online--;
      }
    }
    max_online = max(max_online, online);
    for (int j = 0; j < event[i].size(); ++j) {
      if (event[i][j].second == 1) continue;
      online--;
      if (event[i][j].first > 0 &&
          id[event[i][j].first - 1] == id[event[i][j].first])
        online++;
    }
  }
  if (max_online < m) {
    puts("No solution");
  } else {
    printf("%d\n", user);
    for (int i = 0; i < n; ++i) {
      printf("%d\n", id[i]);
    }
  }
  return 0;
}
