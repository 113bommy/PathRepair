#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
multiset<int> second[5];
vector<int> vec[5];
int main() {
  optimizeIO();
  int n;
  cin >> n;
  int temp = n;
  while (temp--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    second[1].insert(x1);
    second[2].insert(x2);
    second[3].insert(y1);
    second[4].insert(y2);
    vec[1].push_back(x1);
    vec[2].push_back(x2);
    vec[3].push_back(y1);
    vec[4].push_back(y2);
  }
  for (int i = 0; i < n; i++) {
    second[1].erase(second[1].find(vec[1][i]));
    second[2].erase(second[2].find(vec[2][i]));
    second[3].erase(second[3].find(vec[3][i]));
    second[4].erase(second[4].find(vec[4][i]));
    int maxsx = *second[1].rbegin();
    int minex = *second[2].begin();
    int maxsy = *second[3].rbegin();
    int miney = *second[4].begin();
    if (maxsx <= minex && maxsy <= miney) {
      cout << maxsx << " " << maxsy << endl;
      return 0;
    }
    second[1].insert(vec[1][i]);
    second[2].insert(vec[2][i]);
    second[3].insert(vec[3][i]);
    second[4].insert(vec[4][i]);
  }
}
