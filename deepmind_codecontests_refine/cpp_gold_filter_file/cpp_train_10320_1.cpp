#include <bits/stdc++.h>
int n, a, b, en, A, B;
bool frst = true;
std::vector<std::pair<int, int> > v(200007);
std::vector<int> ans;
void make(int it) {
  ans.push_back(it);
  int nxt;
  if (v[it].first != 0) {
    nxt = v[it].first;
    v[it].first = 0;
  } else {
    nxt = v[it].second;
    v[it].second = 0;
  }
  if (v[nxt].first == it) {
    v[nxt].first = 0;
  } else {
    v[nxt].second = 0;
  }
  if (nxt != en) {
    make(nxt);
  }
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a >> b;
    if (frst) {
      en = a;
      frst = false;
    }
    if (v[a].first == 0) {
      v[a].first = b;
    } else {
      v[a].second = b;
    }
    if (v[b].first == 0) {
      v[b].first = a;
    } else {
      v[b].second = a;
    }
  }
  make(en);
  if (ans[2] == 1) {
    for (int i = 0; i < n; ++i) {
      std::cout << ans[(n - i) % n] << " ";
    }
  } else {
    for (int i = 0; i < n; ++i) {
      std::cout << ans[i] << " ";
    }
  }
}
