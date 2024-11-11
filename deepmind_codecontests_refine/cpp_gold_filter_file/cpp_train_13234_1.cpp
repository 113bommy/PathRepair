#include <bits/stdc++.h>
using namespace std;
map<string, long long> mp;
long long cnt;
map<string, string> mp2;
string str = "ACGT";
long long side[12][300011];
long long up[12][300011];
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, m, x, y, n, z, p, k, T;
  string s1, s2, s3;
  x = 1;
  cin >> n >> m;
  char a[n][m];
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> a[i][j];
  for (long long ci = 0; ci < 4; ++ci) {
    for (long long cj = 0; cj < 4; ++cj) {
      if (ci == cj) continue;
      p = 0;
      long long idx = cnt;
      string s;
      s += str[ci];
      s += str[cj];
      mp[s] = cnt++;
      string s2;
      for (long long io = 0; io < 4; ++io)
        if (io != ci && io != cj) s2 += str[io];
      mp2[s] = s2;
      for (i = 0; i < n; ++i) {
        p = 0;
        for (j = 0; j < m; ++j) {
          if (j % 2) {
            if (a[i][j] != str[cj]) ++p;
          }
          if (j % 2 == 0) {
            if (a[i][j] != str[ci]) ++p;
          }
        }
        side[idx][i] = p;
      }
    }
  }
  cnt = 0;
  for (long long ci = 0; ci < 4; ++ci) {
    for (long long cj = 0; cj < 4; ++cj) {
      if (ci == cj) continue;
      p = 0;
      long long idx = cnt;
      string s;
      s += str[ci];
      s += str[cj];
      mp[s] = cnt++;
      for (i = 0; i < m; ++i) {
        p = 0;
        for (j = 0; j < n; ++j) {
          if (j % 2)
            if (a[j][i] != str[cj]) ++p;
          if (j % 2 == 0)
            if (a[j][i] != str[ci]) ++p;
        }
        up[idx][i] = p;
      }
    }
  }
  p = 1e17;
  for (auto x : mp) {
    string other = mp2[x.first];
    vector<string> v;
    v.push_back(other);
    reverse(other.begin(), other.end());
    v.push_back(other);
    long long cost = 0;
    for (auto o : v) {
      long long id = 0;
      cost = 0;
      for (id = 0; id < n; ++id) {
        if (id == 0)
          cost += side[x.second][0];
        else if (id == 1)
          cost += side[mp[o]][1];
        else {
          if (id % 2 == 0) {
            string oth = string(x.first);
            reverse(oth.begin(), oth.end());
            cost += (min(side[mp[x.first]][id], side[mp[oth]][id]));
          } else {
            string oth = string(o);
            reverse(oth.begin(), oth.end());
            cost += (min(side[mp[o]][id], side[mp[oth]][id]));
          }
        }
      }
      p = min(p, cost);
    }
  }
  for (auto x : mp) {
    string other = mp2[x.first];
    vector<string> v;
    v.push_back(other);
    reverse(other.begin(), other.end());
    v.push_back(other);
    long long cost = 0;
    for (auto o : v) {
      long long id = 0;
      cost = 0;
      for (id = 0; id < m; ++id) {
        if (id == 0)
          cost += up[x.second][0];
        else if (id == 1)
          cost += up[mp[o]][1];
        else {
          if (id % 2 == 0) {
            string oth = string(x.first);
            reverse(oth.begin(), oth.end());
            cost += (min(up[mp[x.first]][id], up[mp[oth]][id]));
          } else {
            string oth = string(o);
            reverse(oth.begin(), oth.end());
            cost += (min(up[mp[o]][id], up[mp[oth]][id]));
          }
        }
      }
      p = min(p, cost);
    }
  }
  for (auto x : mp) {
    string other = mp2[x.first];
    vector<string> v;
    v.push_back(other);
    reverse(other.begin(), other.end());
    v.push_back(other);
    long long cost = 0;
    for (auto o : v) {
      long long id = 0;
      cost = 0;
      for (id = 0; id < n; ++id) {
        if (id == 0)
          cost += side[x.second][0];
        else if (id == 1)
          cost += side[mp[o]][1];
        else {
          if (id % 2 == 0) {
            string oth = string(x.first);
            reverse(oth.begin(), oth.end());
            cost += (min(side[mp[x.first]][id], side[mp[oth]][id]));
          } else {
            string oth = string(o);
            reverse(oth.begin(), oth.end());
            cost += (min(side[mp[o]][id], side[mp[oth]][id]));
          }
        }
      }
      if (p == cost) {
        for (i = 0; i < n; ++i) {
          if (i == 0) {
            for (j = 0; j < m; ++j) a[0][j] = x.first[j % 2];
          } else if (i == 1) {
            for (j = 0; j < m; ++j) a[1][j] = o[j % 2];
          } else {
            if (i % 2 == 0) {
              string oth = string(x.first);
              reverse(oth.begin(), oth.end());
              if (side[mp[x.first]][i] < side[mp[oth]][i])
                for (j = 0; j < m; ++j) a[i][j] = x.first[j % 2];
              else
                for (j = 0; j < m; ++j) a[i][j] = oth[j % 2];
            } else {
              string oth = string(o);
              reverse(oth.begin(), oth.end());
              if (side[mp[o]][i] < side[mp[oth]][i])
                for (j = 0; j < m; ++j) a[i][j] = o[j % 2];
              else
                for (j = 0; j < m; ++j) a[i][j] = oth[j % 2];
            }
          }
        }
        for (i = 0; i < n; ++i) {
          for (j = 0; j < m; ++j) cout << a[i][j];
          cout << "\n";
        }
        return 0;
      }
    }
  }
  for (auto x : mp) {
    string other = mp2[x.first];
    vector<string> v;
    v.push_back(other);
    reverse(other.begin(), other.end());
    v.push_back(other);
    long long cost = 0;
    for (auto o : v) {
      long long id = 0;
      cost = 0;
      for (id = 0; id < m; ++id) {
        if (id == 0)
          cost += up[x.second][0];
        else if (id == 1)
          cost += up[mp[o]][1];
        else {
          if (id % 2 == 0) {
            string oth = string(x.first);
            reverse(oth.begin(), oth.end());
            cost += (min(up[mp[x.first]][id], up[mp[oth]][id]));
          } else {
            string oth = string(o);
            reverse(oth.begin(), oth.end());
            cost += (min(up[mp[o]][id], up[mp[oth]][id]));
          }
        }
      }
      if (p == cost) {
        for (i = 0; i < m; ++i) {
          if (i == 0) {
            for (j = 0; j < n; ++j) a[j][i] = x.first[j % 2];
          } else if (i == 1) {
            for (j = 0; j < n; ++j) a[j][i] = o[j % 2];
          } else {
            if (i % 2 == 0) {
              string oth = string(x.first);
              reverse(oth.begin(), oth.end());
              if (up[mp[x.first]][i] < up[mp[oth]][i])
                for (j = 0; j < n; ++j) a[j][i] = x.first[j % 2];
              else
                for (j = 0; j < n; ++j) a[j][i] = oth[j % 2];
            } else {
              string oth = string(o);
              reverse(oth.begin(), oth.end());
              if (up[mp[o]][i] < up[mp[oth]][i])
                for (j = 0; j < n; ++j) a[j][i] = o[j % 2];
              else
                for (j = 0; j < n; ++j) a[j][i] = oth[j % 2];
            }
          }
        }
        for (i = 0; i < n; ++i) {
          for (j = 0; j < m; ++j) cout << a[i][j];
          cout << "\n";
        }
        return 0;
      }
    }
  }
  return 0;
}
