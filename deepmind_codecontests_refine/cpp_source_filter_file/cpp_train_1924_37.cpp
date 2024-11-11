#include <bits/stdc++.h>
using namespace std;
double total = 0;
int k;
int countinv(vector<int> &vs) {
  int size = vs.size();
  int count = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; j++) {
      if (vs[j] < vs[i]) {
        count++;
      }
    }
  }
  return count;
}
vector<int> operate(vector<int> vs, vector<int> &vg) {
  for (int i = 0; i < k; ++i) {
    int l = vg[2 * i];
    int r = vg[2 * i + 1];
    reverse(vs.begin() + l - 1, vs.begin() + r);
  }
  return vs;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n >> k;
  vector<int> v;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int s = (n * (n + 1)) / 2;
  int l = 1;
  pair<int, int> arr[s + 1];
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      arr[l] = make_pair(i, j);
      l++;
    }
  }
  if (k == 4)
    for (int i = 1; i <= s; ++i) {
      for (int j = 1; j <= s; ++j) {
        for (int m = 1; m <= s; ++m) {
          for (int z = 1; z <= s; ++z) {
            vector<int> vp;
            vp.push_back(arr[i].first);
            vp.push_back(arr[i].second);
            vp.push_back(arr[j].first);
            vp.push_back(arr[j].second);
            vp.push_back(arr[m].first);
            vp.push_back(arr[m].second);
            vp.push_back(arr[z].first);
            vp.push_back(arr[z].second);
            vector<int> vf = operate(v, vp);
            total += (countinv(vf));
          }
        }
      }
    }
  if (k == 3)
    for (int i = 1; i <= s; ++i) {
      for (int j = 1; j <= s; ++j) {
        for (int m = 1; m <= s; ++m) {
          {
            vector<int> vp;
            vp.push_back(arr[i].first);
            vp.push_back(arr[i].second);
            vp.push_back(arr[j].first);
            vp.push_back(arr[j].second);
            vp.push_back(arr[m].first);
            vp.push_back(arr[m].second);
            vector<int> vf = operate(v, vp);
            total += (countinv(vf));
          }
        }
      }
    }
  if (k == 2)
    for (int i = 1; i <= s; ++i) {
      for (int j = 1; j <= s; ++j) {
        {
          {
            vector<int> vp;
            vp.push_back(arr[i].first);
            vp.push_back(arr[i].second);
            vp.push_back(arr[j].first);
            vp.push_back(arr[j].second);
            vector<int> vf = operate(v, vp);
            total += (countinv(vf));
          }
        }
      }
    }
  if (k == 1)
    for (int i = 1; i <= s; ++i) {
      vector<int> vp;
      vp.push_back(arr[i].first);
      vp.push_back(arr[i].second);
      vector<int> vf = operate(v, vp);
      total += (countinv(vf));
    }
  long long number = 1;
  for (int i = 0; i < k; ++i) {
    number = number * s;
  }
  cout << setprecision(9) << total / number;
}
