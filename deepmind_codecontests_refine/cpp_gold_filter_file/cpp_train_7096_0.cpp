#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long l = v.size();
  for (long long i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
int n, m;
vector<pair<int, int> > v1, v2;
vector<pair<int, int> > merged;
vector<int> ans;
int get_index(int key) {
  int l = 0, r = merged.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (key >= merged[mid].first and key <= merged[mid].second) {
      return mid;
    }
    if (key > merged[mid].second) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int typ, l, r;
    cin >> typ >> l >> r;
    if (typ == 1) {
      v1.push_back(make_pair(l, r));
    } else {
      v2.push_back(make_pair(l, r));
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  if (v1.size() > 0) {
    merged.push_back(v1[0]);
  }
  for (int i = 1; i < v1.size(); i++) {
    int l = v1[i].first, r = v1[i].second;
    if (l > merged[merged.size() - 1].second) {
      merged.push_back(v1[i]);
      continue;
    }
    if (r > merged[merged.size() - 1].second) {
      merged[merged.size() - 1].second = r;
    }
  }
  for (int i = 0; i < v2.size(); i++) {
    int ind1 = get_index(v2[i].first);
    int ind2 = get_index(v2[i].second);
    if (ind1 == -1 or ind2 == -1) {
      continue;
    }
    if (ind1 == ind2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  ans.resize(n + 1);
  int curr = 0;
  int num = 1e9 / 2;
  ans[0] = num + 1;
  for (int i = 1; i <= n; i++) {
    if (curr < merged.size()) {
      if (i > merged[curr].first and i <= merged[curr].second) {
        ans[i] = num;
      } else if (i <= merged[curr].first) {
        ans[i] = ans[i - 1] - 1;
      } else {
        num--;
        ans[i] = num;
        curr++;
      }
    } else {
      ans[i] = ans[i - 1] - 1;
    }
    num = ans[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
