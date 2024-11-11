#include <bits/stdc++.h>
clock_t t_;
using namespace std;
template <class T>
void print(T s) {
  cout << s << "\n";
}
template <class T>
void emax(T &a, T b) {
  a = (a < b ? b : a);
};
template <class T>
void emin(T &a, T b) {
  a = (a > b ? b : a);
}
template <class T>
void printC(T s) {
  for (auto &x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int sum[55];
int a[55];
map<int, vector<pair<int, int> > > rangos;
int main(int argc, const char *argv[]) {
  t_ = clock();
  int n;
  cin >> n;
  for (int i = int(1); i < int(n + 1); i++) {
    cin >> a[i];
  }
  for (int i = int(1); i < int(n + 1); i++) sum[i] = sum[i - 1] + a[i];
  for (int i = int(1); i < int(n + 1); i++) {
    for (int j = int(i); j < int(n + 1); j++) {
      int ret = sum[j] - sum[i - 1];
      rangos[ret].push_back({i, j});
    }
  }
  long long smAns = 0, size = 0;
  int tmp = 0;
  for (auto suma : rangos) {
    tmp = 0;
    int actR = 0;
    vector<pair<int, int> > ret;
    for (auto x : suma.second) {
      if (x.first > actR) {
        tmp++;
        actR = x.second;
      } else if (x.second < actR) {
        actR = x.second;
      }
    }
    if (tmp > size) {
      size = tmp;
      smAns = suma.first;
    }
  }
  print(size);
  int actR = 0;
  vector<pair<int, int> > ans;
  for (auto x : rangos[smAns]) {
    if (x.first > actR) {
      ans.push_back(x);
      actR = x.second;
    } else if (x.second < actR) {
      ans.pop_back();
      ans.push_back(x);
      actR = x.second;
    }
  }
  for (auto x : ans) {
    cout << x.first << " " << x.second << "\n";
  }
  t_ = clock() - t_;
  cerr << setprecision(9) << fixed << ((float)t_ / CLOCKS_PER_SEC) << endl;
  return 0;
}
