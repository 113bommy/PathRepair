#include <bits/stdc++.h>
using namespace std;
template <class T>
void read_vector(vector<T>& a, int n) {
  while (n-- > 0) {
    T x;
    cin >> x;
    a.push_back(x);
  }
}
using namespace std;
int count_larger(vector<int> a, vector<int> b) {
  int c = 0;
  for (int i = 0; i < b.size(); i++) {
    if (b[i] > a[i]) {
      c++;
    }
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a;
  read_vector(a, n);
  sort(a.begin(), a.end());
  int ans = 0;
  vector<int> a_copy = a;
  unordered_map<int, int> longest_run;
  for (const auto x : a) {
    if (longest_run.find(x) == longest_run.end()) {
      longest_run[x]++;
    } else {
      longest_run[x] = 1;
    }
  }
  int l = 0;
  for (const auto x : longest_run) {
    l = max(l, x.second);
  }
  rotate(a_copy.begin(), a_copy.begin() + l + 1, a_copy.end());
  cout << count_larger(a, a_copy) << endl;
}
