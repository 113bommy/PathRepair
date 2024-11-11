#include <bits/stdc++.h>
struct room {
  long long int length;
  long long int width;
  long long int height;
};
struct paper {
  long long int length;
  long long int width;
  long long int cost;
};
int main() {
  long long int n = 0;
  std::cin >> n;
  std::vector<room> rooms(n);
  for (long long int i = 0; i < n; ++i) {
    long long int l = 0, w = 0, h = 0;
    std::cin >> l >> w >> h;
    rooms[i] = room{l, w, h};
  }
  long long int m = 0;
  std::cin >> m;
  std::vector<paper> papers(m);
  for (long long int i = 0; i < m; ++i) {
    long long int l = 0, w = 0, c = 0;
    std::cin >> l >> w >> c;
    papers[i] = paper{l, w, c};
  }
  long long int sum = 0;
  long long int const inf = std::numeric_limits<long long int>::max();
  for (long long int i = 0; i < n; ++i) {
    long long int around = (rooms[i].length + rooms[i].width) * 2;
    long long int height = rooms[i].height;
    long long int min = inf;
    for (long long int j = 0; j < m; ++j) {
      if (papers[j].length >= height) {
        long long int d = papers[j].width * papers[j].length / height;
        long long int c = papers[j].cost * (around / d);
        if ((around % d) != 0) c += papers[j].cost;
        min = std::min(min, c);
      }
    }
    sum += min;
  }
  std::cout << sum << std::endl;
}
