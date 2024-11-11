#include <bits/stdc++.h>
using namespace std;
vector<list<int>> EdgeList;
bool visited[100000];
long long Pow(long long x, long long y) {
  if (y == 0) return 1;
  long long a = Pow(x, y / 2);
  if (y % 2) return a * a * x;
  return a * a;
}
vector<std::pair<long long, long long>> div(long long x, long long y,
                                            long long z) {
  vector<std::pair<long long, long long>> v;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      if (i < z && x / i <= (y / (z - 1))) v.push_back(make_pair(i, x / i));
    }
  }
  return v;
}
vector<std::pair<long long, long long>> intersecion(
    vector<std::pair<long long, long long>> x,
    vector<std::pair<long long, long long>> y) {
  vector<std::pair<long long, long long>> z;
  for (int i = 0; i < (int)x.size(); i++) {
    for (int j = 0; j < (int)y.size(); i++) {
      if (x[i].first == y[j].first || x[i].first == y[j].second) {
        z.push_back(make_pair(x[i].second, x[i].first));
        break;
      } else if (x[i].second == y[i].first || x[i].second == y[j].second) {
        z.push_back(x[i]);
        break;
      }
    }
  }
  return z;
}
vector<int> zero;
bool binary(int x, int y) {
  int d = 0, f = zero.size() - 1;
  int res1 = -1, res2 = -1;
  while (d <= f && res1 == -1) {
    int mid = (d + f) / 2;
    if (zero[mid] >= x) {
      if (mid > 0 && zero[mid] < x) res1 = mid;
      if (mid == 0)
        res1 = 0;
      else
        f = mid - 1;
    } else {
      if (mid < (int)zero.size() - 1 && zero[mid + 1] >= x)
        res1 = mid + 1;
      else if (mid == (int)zero.size() - 1)
        res1 = (int)zero.size() - 1;
      else
        d = mid + 1;
    }
  }
  d = 0;
  f = zero.size() - 1;
  while (d <= f && res2 == -1) {
    int mid = (d + f) / 2;
    if (zero[mid] < y) {
      if (mid < (int)zero.size() - 1 && zero[mid + 1] > y)
        res2 = mid;
      else if (mid == (int)(zero.size()) - 1)
        res2 = mid;
      else
        d = mid + 1;
    } else {
      if (mid > 0 && zero[mid - 1] < y)
        res2 = mid - 1;
      else if (mid == 0)
        res2 = 0;
      else
        f = mid - 1;
    }
  }
  if (res1 != -1 && res2 != -1 && (zero[res1] >= x) && (zero[res2] < y) &&
      zero[res1] <= zero[res2])
    return true;
  else
    return false;
}
int main() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  int idx[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++) idx[b[i]] = i;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '0') zero.push_back(i);
  }
  bool bol;
  for (int i = 0; i < n; i++) {
    if (idx[a[i]] != i) {
      bol = binary(min(idx[a[i]], i), max(idx[a[i]], i));
      if (bol) return cout << "NO" << endl, 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
