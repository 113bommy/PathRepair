#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
const int Mod = 1000000007, Mod2 = 998244353;
const int MOD = Mod2;
const int maxn = 100005;
int n, a[maxn];
vector<vector<int>> res;
vector<int> vec, things[maxn];
vector<pair<int, int>> things2[maxn];
void act(int x, int y, int z) {
  if (x > y) swap(x, y);
  if (x > z) swap(x, z);
  if (y > z) swap(y, z);
  res.push_back({x, y, z});
  a[x] ^= 1, a[y] ^= 1, a[z] ^= 1;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = (0); i < ((int)(n)); i++) cin >> a[i];
  if (n <= 15) {
    vector<int> basis, ori, comp;
    int target = 0;
    for (int i = (0); i < ((int)(n)); i++) target ^= a[i] * (1ll << (i));
    for (int i = (0); i < ((int)(n)); i++)
      for (int j = (i + 1); j < ((int)(n)); j++)
        for (int k = (j + 1); k < ((int)(n)); k++)
          if (j - i == k - j) {
            int x = (1ll << (i)) + (1ll << (j)) + (1ll << (k)), val = 0;
            for (int z = (0); z < ((int)(((int)basis.size()))); z++)
              if ((x ^ basis[z]) < x) x ^= basis[z], val ^= comp[z];
            if (x) {
              basis.push_back(x);
              ori.push_back((1ll << (i)) + (1ll << (j)) + (1ll << (k)));
              comp.push_back(val ^ (1ll << (((int)basis.size()) - 1)));
            }
          }
    int val = 0;
    for (int i = (0); i < ((int)(((int)basis.size()))); i++)
      if ((target ^ basis[i]) < target) target ^= basis[i], val ^= comp[i];
    if (target) {
      print("NO");
      return 0;
    }
    print("YES");
    print(__builtin_popcountll(val));
    for (int i = (0); i < ((int)(((int)basis.size()))); i++)
      if (val & (1ll << (i))) {
        for (int j = (0); j < ((int)(n)); j++)
          if (ori[i] & (1ll << (j))) cout << (j + 1) << ' ';
        cout << "\n";
      }
    return 0;
  }
  for (int i = (0); i < ((int)(n / 3)); i++)
    if (a[3 * i] && a[3 * i + 1] && a[3 * i + 2])
      act(3 * i, 3 * i + 1, 3 * i + 2);
  for (int j = (1); j < ((int)(10)); j++)
    for (int i = (0); i < ((int)(n - 2 * j)); i++)
      if (a[i] && a[i + j] && a[i + 2 * j]) act(i, i + j, i + 2 * j);
  for (int _ = (0); _ < ((int)(2)); _++) {
    vec.clear();
    for (int i = (0); i < ((int)(n)); i++)
      if (a[i] && i % 2 == _) vec.push_back(i);
    for (int i = (0); i < ((int)(((int)vec.size()) - 1)); i++)
      things[vec[i + 1] - vec[i]].push_back(vec[i]);
    for (int i = (0); i < ((int)(n)); i++)
      if (!things[i].empty()) {
        auto& v = things[i];
        vec.clear();
        for (int j = (0); j < ((int)(((int)v.size()) - 1)); j++)
          if (v[j] + i == v[j + 1] && a[v[j]] && a[v[j] + i] && a[v[j] + 2 * i])
            act(v[j], v[j] + i, v[j] + 2 * i);
        for (int j = (0); j < ((int)(((int)v.size()) - 1)); j++)
          if (a[v[j]] && a[v[j] + i]) vec.push_back(v[j]);
        v = vec;
        for (int j = (0); j < ((int)(((int)v.size()) >> 1)); j++)
          act(v[j * 2], (v[j * 2] + v[j * 2 + 1] + i) / 2, v[j * 2 + 1] + i),
              act(v[j * 2] + i, (v[j * 2] + v[j * 2 + 1] + i) / 2,
                  v[j * 2 + 1]);
        v.clear();
      }
  }
  vec.clear();
  for (int i = (0); i < ((int)(n)); i++)
    if (a[i]) vec.push_back(i);
  for (int i = (0); i < ((int)(((int)vec.size()))); i++)
    for (int j = (i + 1); j < ((int)(((int)vec.size()))); j++) {
      if (vec[i] * 2 - vec[j] >= 0) {
        if (a[vec[i] * 2 - vec[j]] && a[vec[i]] && a[vec[j]])
          act(vec[i] * 2 - vec[j], vec[i], vec[j]);
        else
          things2[vec[i] * 2 - vec[j]].push_back({vec[i], vec[j]});
      }
      if ((vec[i] + vec[j]) % 2 == 0) {
        if (a[vec[i] + vec[j] >> 1] && a[vec[i]] && a[vec[j]])
          act(vec[i] + vec[j] >> 1, vec[i], vec[j]);
        else
          things2[vec[i] + vec[j] >> 1].push_back({vec[i], vec[j]});
      }
      if (vec[j] * 2 - vec[i] < n) {
        if (a[vec[j] * 2 - vec[i]] && a[vec[i]] && a[vec[j]])
          act(vec[j] * 2 - vec[i], vec[i], vec[j]);
        else
          things2[vec[j] * 2 - vec[i]].push_back({vec[i], vec[j]});
      }
    }
  for (int i = (0); i < ((int)(n)); i++)
    if (!things2[i].empty()) {
      auto& v = things2[i];
      vector<pair<int, int>> vec1;
      for (auto& [x, y] : v)
        if (a[x] && a[y]) vec1.push_back({x, y});
      v = vec1;
      for (int j = (0); j < ((int)(((int)v.size()) >> 1)); j++)
        if (((int)set<int>({v[j * 2].first, v[j * 2].second, v[j * 2 + 1].first,
                            v[j * 2 + 1].second})
                 .size()) == 4 &&
            a[v[j * 2].first] && a[v[j * 2].second] && a[v[j * 2 + 1].first] &&
            a[v[j * 2 + 1].second])
          act(i, v[j * 2].first, v[j * 2].second),
              act(i, v[j * 2 + 1].first, v[j * 2 + 1].second);
    }
  set<int> st;
  for (int i = (0); i < ((int)(n)); i++)
    if (a[i]) st.insert(i);
  while (((int)st.size()) >= 3) {
    auto it1 = st.begin(), it2 = next(it1), it3 = next(it2);
    int x = *it1, y = *it2, z = *it3;
    if (y - x == z - y) {
      act(x, y, z);
      for (int i = (0); i < ((int)(3)); i++) st.erase(st.begin());
    } else if (y - x < z - y) {
      act(x, y, 2 * y - x);
      st.erase(x), st.erase(y);
      st.insert(2 * y - x);
    } else {
      act(2 * y - z, y, z);
      st.erase(y), st.erase(z);
      st.insert(2 * y - z);
    }
  }
  while (((int)st.size())) {
    int x = *st.begin();
    if (x >= 7) {
      act(x - 6, x - 5, x - 4), act(x - 5, x - 4, x - 3), act(x - 6, x - 3, x);
    } else {
      act(x + 3, x + 4, x + 5), act(x + 4, x + 5, x + 6), act(x, x + 3, x + 6);
    }
    st.erase(st.begin());
  }
  print("YES");
  print(((int)res.size()));
  for (auto& vec : res) {
    for (auto i : vec) cout << (i + 1) << ' ';
    cout << "\n";
  }
  return 0;
}
