#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> a;
map<int, int> cnt;
map<int, vector<int> > all;
void in() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  all[0].push_back(0);
  all[1].push_back(1);
  all[1].push_back(2);
  for (int i = 1; i <= N; i++) {
    char c;
    cin >> c;
    a.push_back((c - '0'));
    all[a.back()].push_back(i - 1);
    cnt[a.back()]++;
  }
}
void solution() {
  int need = N / 3;
  if (cnt[0] == need && cnt[1] == need && cnt[2] == need) {
    for (int i = 0; i < N; i++) {
      cout << a[i];
    }
    return;
  }
  vector<int> ub, izb;
  for (int i = 0; i < 3; i++) {
    if (cnt[i] < need) {
      ub.push_back(i);
    } else {
      if (cnt[i] > need) izb.push_back(i);
    }
  }
  if (ub.size() == 2) {
    if (izb[0] == 0) {
      ub[0] = 2;
      ub[1] = 1;
    } else {
      sort(ub.begin(), ub.end());
    }
  }
  int ub_size = ub.size();
  for (int k = 0; k < ub_size; k++) {
    int izb_size = izb.size();
    int dif = need - cnt[ub[k]];
    int to = ub[k];
    for (int j = 0; j < izb_size; j++) {
      int from = izb[j];
      int dif1 = min(max(cnt[from] - need, 0), dif);
      dif -= dif1;
      cnt[from] -= dif1;
      if (to < from) {
        for (int i = 1; i <= dif1; i++) {
          a[all[from][i + all[from][0]]] = to;
          all[from][0]++;
        }
      } else {
        int sz = all[from].size() - 1;
        for (int i = 0; i < dif1; i++) {
          a[all[from][sz - i]] = to;
          all[from].pop_back();
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << a[i];
  }
}
void out() {}
int main() {
  in();
  solution();
  out();
  return 0;
}
