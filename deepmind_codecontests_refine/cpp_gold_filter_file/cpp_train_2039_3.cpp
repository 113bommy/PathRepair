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
int n, counter;
set<string> s;
int done[2000];
string words[2000][2], temp, temp2;
string ans[2000];
string f1[2000];
string f2[2000];
int ind[2000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    f1[i] = a.substr(0, 3);
    f2[i] = a.substr(0, 2) + b.substr(0, 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (f1[i] == f1[j]) {
        done[i] = 1;
        done[j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (done[i] == 1) {
      if (s.find(f2[i]) != s.end()) {
        cout << "NO\n";
        return 0;
      } else {
        s.insert(f2[i]);
        ans[i] = f2[i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (done[j] == 1) {
        continue;
      } else if (s.find(f1[j]) != s.end()) {
        done[j] = 1;
        if (s.find(f2[j]) != s.end()) {
          cout << "NO\n";
          return 0;
        } else {
          s.insert(f2[j]);
          ans[j] = f2[j];
          break;
        }
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    if (done[i] == 1) {
      cout << ans[i] << "\n";
    } else {
      cout << f1[i] << "\n";
    }
  }
  return 0;
}
