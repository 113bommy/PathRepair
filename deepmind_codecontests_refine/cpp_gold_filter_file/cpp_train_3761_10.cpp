#include <bits/stdc++.h>
using namespace std;
int t, n, k, v['z' + 5], w['z' + 5];
char f['z' + 5], g['z' + 5];
string a, b, s;
void Print() {
  int j = 'a';
  for (int i = 'a'; i < 'a' + k; i++) {
    while (j < 'a' + k - 1 && v[j]) j++;
    if (!f[i]) f[i] = j, v[j] = 1;
    cout << f[i];
  }
  cout << '\n';
}
void Print2() {
  int j = 'a';
  for (int i = 'a'; i < 'a' + k; i++) {
    while (j < 'a' + k - 1 && w[j]) j++;
    if (!g[i]) g[i] = j, w[j] = 1;
    cout << g[i];
  }
  cout << '\n';
}
bool Trya(int i) {
  for (int i = 'a'; i < 'a' + k; i++) {
    g[i] = f[i];
    w[i] = v[i];
  }
  int first = 'a' + k - 1;
  for (int j = i + 1; j < n; j++) {
    if (!g[s[j]]) {
      while (first > 'a' && w[first]) first--;
      g[s[j]] = first;
      w[first] = 1;
    }
    if (g[s[j]] < a[j]) {
      return 0;
    } else if (g[s[j]] > a[j]) {
      cout << "YES\n";
      Print2();
      return 1;
    }
  }
  cout << "YES\n";
  Print2();
  return 1;
}
bool Tryb(int i) {
  for (int i = 'a'; i < 'a' + k; i++) {
    g[i] = f[i];
    w[i] = v[i];
  }
  int first = 'a';
  for (int j = i + 1; j < n; j++) {
    if (!g[s[j]]) {
      while (first < 'a' + k - 1 && w[first]) first++;
      g[s[j]] = first;
      w[first] = 1;
    }
    if (g[s[j]] > b[j]) {
      return 0;
    } else if (g[s[j]] < b[j]) {
      cout << "YES\n";
      Print2();
      return 1;
    }
  }
  cout << "YES\n";
  Print2();
  return 1;
}
void Try() {
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (f[s[i]]) {
        if (f[s[i]] < a[i] || f[s[i]] > b[i]) {
          cout << "NO\n";
          return;
        } else if (f[s[i]] > a[i] && f[s[i]] < b[i]) {
          cout << "YES\n";
          Print();
          return;
        } else if (f[s[i]] == a[i]) {
          int first = 'a' + k - 1;
          for (int j = i + 1; j < n; j++) {
            if (!f[s[j]]) {
              while (first > 'a' && v[first]) first--;
              f[s[j]] = first;
              v[first] = 1;
            }
            if (f[s[j]] < a[j]) {
              cout << "NO\n";
              return;
            } else if (f[s[j]] > a[j]) {
              cout << "YES\n";
              Print();
              return;
            }
          }
          cout << "YES\n";
          Print();
          return;
        } else {
          int first = 'a';
          for (int j = i + 1; j < n; j++) {
            if (!f[s[j]]) {
              while (first < 'a' + k - 1 && v[first]) first++;
              f[s[j]] = first;
              v[first] = 1;
            }
            if (f[s[j]] > b[j]) {
              cout << "NO\n";
              return;
            } else if (f[s[j]] < b[j]) {
              cout << "YES\n";
              Print();
              return;
            }
          }
          cout << "YES\n";
          Print();
          return;
        }
      } else {
        for (int j = a[i] + 1; j <= b[i] - 1; j++) {
          if (!v[j]) {
            f[s[i]] = j;
            v[j] = 1;
            cout << "YES\n";
            Print();
            return;
          }
        }
        if (!v[a[i]]) {
          f[s[i]] = a[i];
          v[a[i]] = 1;
          if (Trya(i)) return;
          f[s[i]] = 0;
          v[a[i]] = 0;
        }
        if (!v[b[i]]) {
          f[s[i]] = b[i];
          v[b[i]] = 1;
          if (Tryb(i)) return;
          f[s[i]] = 0;
          v[b[i]] = 0;
        }
        cout << "NO\n";
        return;
      }
    } else {
      if (f[s[i]] && f[s[i]] != a[i]) {
        cout << "NO\n";
        return;
      } else if (!f[s[i]] && v[a[i]]) {
        cout << "NO\n";
        return;
      } else
        f[s[i]] = a[i], v[a[i]] = 1;
    }
  }
  cout << "YES\n";
  Print();
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> t;
  while (t--) {
    cin >> k >> s >> a >> b;
    n = s.length();
    for (int i = 'a'; i <= 'z'; i++) f[i] = 0, v[i] = 0;
    Try();
  }
}
