#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000000];
int nx_suff[1000000];
int nx_pref[1000000];
vector<int> ls;
const int sh = 1 << 19;
int rm[2 * sh + 10];
const int inf = (int)2e9 + 10;
void add(int first, int v) {
  int p = (int)(lower_bound((ls).begin(), (ls).end(), first) - ls.begin());
  p += sh;
  while (p >= 1) {
    rm[p] = min(rm[p], v);
    p /= 2;
  }
}
int get_min(int first) {
  int l = sh;
  int r = (int)(lower_bound((ls).begin(), (ls).end(), first) - ls.begin()) + sh;
  int res = inf;
  while (l <= r) {
    res = min(res, rm[l]);
    res = min(res, rm[r]);
    l = (l + 1) / 2;
    r = (r - 1) / 2;
  }
  return res;
}
int first[1000000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n + 1; i++) {
    scanf("%d", &first[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
  }
  for (int i = 0; i <= 2 * sh + 3; i++) {
    rm[i] = inf;
  }
  {
    vector<int> st;
    st.push_back(0);
    nx_pref[0] = inf;
    for (int i = 1; i <= n + 1; i++) {
      while ((int)(st).size() >= 2 &&
             first[i] - first[st[(int)(st).size() - 2]] >
                 2 * d[st[(int)(st).size() - 1]]) {
        st.pop_back();
      }
      st.push_back(i);
      nx_pref[i] =
          (int)min((long long)inf,
                   (long long)(2 * d[i] + first[st[(int)(st).size() - 2]]));
    }
  }
  {
    vector<int> st;
    st.push_back(n + 1);
    for (int i = n; i >= 0; i--) {
      while ((int)(st).size() >= 2 &&
             first[st[(int)(st).size() - 2]] - first[i] >
                 2 * d[st[(int)(st).size() - 1]]) {
        st.pop_back();
      }
      st.push_back(i);
      nx_suff[i] = -2 * d[i] + first[st[(int)(st).size() - 2]];
    }
    nx_suff[n + 1] = -inf;
  }
  for (int i = 0; i <= n + 1; i++) {
    ls.push_back(first[i]);
    ls.push_back(nx_pref[i]);
    ls.push_back(nx_suff[i]);
  }
  {
    sort((ls).begin(), (ls).end()),
        ls.resize(unique((ls).begin(), (ls).end()) - ls.begin());
  };
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    if (nx_pref[i] >= first[n + 1]) {
      ans = 0;
    }
  }
  add(nx_suff[n + 1], first[n + 1]);
  for (int i = n; i >= 0; i--) {
    if (nx_pref[i] > first[i]) {
      int val = get_min(nx_pref[i]);
      if (val < inf) {
        ans = min(ans, val - first[i]);
      }
    }
    if (nx_suff[i] < first[i]) {
      add(nx_suff[i], first[i]);
    }
  }
  printf("%.4f\n", (double)ans * 0.5);
  return 0;
}
