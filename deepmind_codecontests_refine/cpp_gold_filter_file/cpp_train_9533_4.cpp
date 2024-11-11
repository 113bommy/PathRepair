#include <bits/stdc++.h>
char s[1000002];
int main() {
  std::string w;
  int h(0), e(0), k, v;
  std::stack<int> d;
  std::vector<std::vector<std::string>> r;
  std::scanf("%s", s);
  r.reserve(10000);
  while (s[e]) {
    while (s[e] != ',') ++e;
    s[e] = '\0';
    w = s + h;
    h = ++e;
    while (s[e] && s[e] != ',') ++e;
    v = 0;
    while (h < e) v = v * 10 + s[h++] - '0';
    h = ++e;
    k = d.size();
    if (r.size() <= k) r.resize(k + 1);
    r[k].push_back(w);
    if (!d.empty()) d.top()--;
    if (0 < v) d.push(v);
    while (!d.empty() && d.top() <= 0) d.pop();
  }
  std::printf("%lu\n", r.size());
  for (auto& l : r) {
    for (int i(0); i < l.size(); ++i) {
      if (0 < i) std::printf(" ");
      std::printf("%s", l[i].c_str());
    }
    std::puts("");
  }
  return 0;
}
