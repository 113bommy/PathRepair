#include <bits/stdc++.h>
using namespace std;
struct str {
  long long gruz;
  int num;
};
bool operator<(const str& i, const str& j) { return i.gruz < j.gruz; }
int main() {
  long N, V, type, vv;
  cin >> N >> V;
  str st;
  vector<str> list_1, list_2;
  list_1.reserve(N);
  list_2.reserve(N);
  for (long Q = 0; Q < N; ++Q) {
    cin >> type >> st.gruz;
    st.num = Q + 1;
    if (type == 1)
      list_1.push_back(st);
    else
      list_2.push_back(st);
  }
  sort(list_1.begin(), list_1.end()), sort(list_2.begin(), list_2.end());
  vector<int> res;
  res.reserve(N);
  long long result = 0;
  while (V > 0 && (list_1.size() >= 1 || list_2.size() >= 1)) {
    if (list_1.size() == 0) {
      if (V >= 2)
        result += list_2.back().gruz, res.push_back(list_2.back().num), V -= 2;
      else
        V = 0;
      list_2.pop_back();
      continue;
    }
    if (list_2.size() == 0) {
      if (V >= 1)
        result += list_1.back().gruz, res.push_back(list_1.back().num), V -= 1;
      else
        V = 0;
      list_1.pop_back();
      continue;
    }
    if (list_1.size() == 1) {
      if (V & 1 == 1) {
        result += list_1.back().gruz;
        res.push_back(list_1.back().num);
        V -= 1;
        list_1.pop_back();
        continue;
      }
      if (list_1.back().gruz > list_2.back().gruz) {
        result += list_1.back().gruz;
        res.push_back(list_1.back().num);
        V -= 1;
        list_1.pop_back();
        continue;
      } else {
        result += list_2.back().gruz;
        res.push_back(list_2.back().num);
        V -= 2;
        list_2.pop_back();
        continue;
      }
    } else {
      if (V & 1 == 1) {
        result += list_1.back().gruz;
        res.push_back(list_1.back().num);
        V -= 1;
        list_1.pop_back();
        continue;
      }
      if (list_1.back().gruz + list_1[list_1.size() - 2].gruz >
          list_2.back().gruz) {
        result += list_1.back().gruz + list_1[list_1.size() - 2].gruz;
        res.push_back(list_1.back().num),
            res.push_back(list_1[list_1.size() - 2].num);
        V -= 2;
        list_1.pop_back(), list_1.pop_back();
        continue;
      } else {
        result += list_2.back().gruz;
        res.push_back(list_2.back().num);
        list_2.pop_back();
        V -= 2;
        continue;
      }
    }
  }
  cout << result << endl;
  for (long Q = 0; Q < res.size(); ++Q) cout << res[Q] << " ";
}
