#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y);
long long mpower(long long x, long long y, long long p);
long long modInv(long long a, long long m);
long long gcdExtended(long long a, long long b, long long *x, long long *y);
bool isPrime(long long n);
long long n, m;
bool isValid(long long x, long long y) {
  if (x < 0 || y < 0 || x >= n || y >= m) {
    return false;
  }
  return true;
}
long long DFS(long long a, long long b, long long x, long long y) {
  a--;
  b--;
  x--;
  y--;
  long long vis[n][m], p, q;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      vis[i][j] = 0;
    }
  }
  queue<pair<long long, long long> > Q;
  Q.push(make_pair(a, b));
  vis[a][b] = 1;
  while (Q.size()) {
    pair<long long, long long> aa = Q.front();
    Q.pop();
    p = aa.first;
    q = aa.second;
    if (isValid(p + 1, q + 2) && vis[p + 1][q + 2] == 0) {
      Q.push(make_pair(p + 1, q + 2));
      vis[p + 1][q + 2] = vis[p][q] + 1;
    }
    if (isValid(p + 1, q - 2) && vis[p + 1][q - 2] == 0) {
      Q.push(make_pair(p + 1, q - 2));
      vis[p + 1][q - 2] = vis[p][q] + 1;
    }
    if (isValid(p - 1, q + 2) && vis[p - 1][q + 2] == 0) {
      Q.push(make_pair(p - 1, q + 2));
      vis[p - 1][q + 2] = vis[p][q] + 1;
    }
    if (isValid(p - 1, q - 2) && vis[p - 1][q - 2] == 0) {
      Q.push(make_pair(p - 1, q - 2));
      vis[p - 1][q - 2] = vis[p][q] + 1;
    }
    if (isValid(p + 2, q + 1) && vis[p + 2][q + 1] == 0) {
      Q.push(make_pair(p + 2, q + 1));
      vis[p + 2][q + 1] = vis[p][q] + 1;
    }
    if (isValid(p + 2, q - 1) && vis[p + 2][q - 1] == 0) {
      Q.push(make_pair(p + 2, q - 1));
      vis[p + 2][q - 1] = vis[p][q] + 1;
    }
    if (isValid(p - 2, q + 1) && vis[p - 2][q + 1] == 0) {
      Q.push(make_pair(p - 2, q + 1));
      vis[p - 2][q + 1] = vis[p][q] + 1;
    }
    if (isValid(p - 2, q - 1) && vis[p - 2][q - 1] == 0) {
      Q.push(make_pair(p - 2, q - 1));
      vis[p - 2][q - 1] = vis[p][q] + 1;
    }
  }
  return vis[x][y];
}
vector<pair<long long, long long> > DFS2(long long a, long long b, long long x,
                                         long long y) {
  a--;
  b--;
  x--;
  y--;
  long long vis[n][m], p, q;
  pair<long long, long long> par[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      vis[i][j] = 0;
    }
  }
  vector<pair<long long, long long> > v;
  queue<pair<long long, long long> > Q;
  Q.push(make_pair(a, b));
  vis[a][b] = 1;
  while (Q.size()) {
    pair<long long, long long> aa = Q.front();
    Q.pop();
    p = aa.first;
    q = aa.second;
    if (isValid(p + 1, q + 2) && vis[p + 1][q + 2] == 0) {
      Q.push(make_pair(p + 1, q + 2));
      vis[p + 1][q + 2] = vis[p][q] + 1;
      par[p + 1][q + 2] = make_pair(p, q);
    }
    if (isValid(p + 1, q - 2) && vis[p + 1][q - 2] == 0) {
      Q.push(make_pair(p + 1, q - 2));
      vis[p + 1][q - 2] = vis[p][q] + 1;
      par[p + 1][q - 2] = make_pair(p, q);
    }
    if (isValid(p - 1, q + 2) && vis[p - 1][q + 2] == 0) {
      Q.push(make_pair(p - 1, q + 2));
      vis[p - 1][q + 2] = vis[p][q] + 1;
      par[p - 1][q + 2] = make_pair(p, q);
    }
    if (isValid(p - 1, q - 2) && vis[p - 1][q - 2] == 0) {
      Q.push(make_pair(p - 1, q - 2));
      vis[p - 1][q - 2] = vis[p][q] + 1;
      par[p - 1][q - 2] = make_pair(p, q);
    }
    if (isValid(p + 2, q + 1) && vis[p + 2][q + 1] == 0) {
      Q.push(make_pair(p + 2, q + 1));
      vis[p + 2][q + 1] = vis[p][q] + 1;
      par[p + 2][q + 1] = make_pair(p, q);
    }
    if (isValid(p + 2, q - 1) && vis[p + 2][q - 1] == 0) {
      Q.push(make_pair(p + 2, q - 1));
      vis[p + 2][q - 1] = vis[p][q] + 1;
      par[p + 2][q - 1] = make_pair(p, q);
    }
    if (isValid(p - 2, q + 1) && vis[p - 2][q + 1] == 0) {
      Q.push(make_pair(p - 2, q + 1));
      vis[p - 2][q + 1] = vis[p][q] + 1;
      par[p - 2][q + 1] = make_pair(p, q);
    }
    if (isValid(p - 2, q - 1) && vis[p - 2][q - 1] == 0) {
      Q.push(make_pair(p - 2, q - 1));
      vis[p - 2][q - 1] = vis[p][q] + 1;
      par[p - 2][q - 1] = make_pair(p, q);
    }
  }
  while (x != a || y != b) {
    v.push_back(make_pair(x + 1, y + 1));
    pair<long long, long long> aa = par[x][y];
    x = aa.first;
    y = aa.second;
  }
  return v;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, k, l, h, p, q, r, x, y, z, a, b, c, d, f, M = 1000000007;
  char ch, ch2, ch3;
  string s, s1, s2, s3;
  vector<pair<long long, long long> > v, w;
  vector<long long>::iterator itrv;
  unordered_map<long long, long long> N;
  set<long long> S;
  set<long long>::iterator itr;
  long long aa, bb, cc, dd, xx, yy, zz;
  cin >> n >> m >> a >> b >> x >> y;
  if ((a + b) % 2 == (x + y) % 2) {
    f = 0;
  } else {
    f = 1;
  }
  aa = DFS(a, b, n / 2, m / 2);
  bb = DFS(x, y, n / 2, m / 2);
  cc = DFS(a, b, n / 2 + 1, m / 2);
  dd = DFS(x, y, n / 2 + 1, m / 2);
  if (f == 0) {
    if (dd < aa || bb <= aa) {
      z = 1;
    } else {
      z = 0;
    }
  } else {
    if (aa <= dd || (cc - 1) <= dd) {
      z = 0;
    } else {
      z = 1;
    }
  }
  if (z) {
    cout << "BLACK" << endl;
  } else {
    cout << "WHITE" << endl;
  }
  if (z) {
    if (f) {
      v = DFS2(x, y, n / 2 + 1, m / 2);
      for (i = (long long)v.size() - 1; i >= 0; i--) {
        cin >> p >> q;
        cout << v[i].first << " " << v[i].second << endl;
      }
    } else {
      if (dd < aa) {
        v = DFS2(x, y, n / 2 + 1, m / 2);
        for (i = (long long)v.size() - 1; i >= 0; i--) {
          cin >> p >> q;
          cout << v[i].first << " " << v[i].second << endl;
          if (p == v[i].first && q == v[i].second) {
            return 0;
          }
        }
      } else {
        v = DFS2(x, y, n / 2, m / 2);
        for (i = (long long)v.size() - 1; i >= 0; i--) {
          cin >> p >> q;
          c = abs(x - p);
          d = abs(y - q);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << p << " " << q << endl;
            return 0;
          } else {
            cout << v[i].first << " " << v[i].second << endl;
            x = v[i].first;
            y = v[i].second;
          }
        }
        cin >> p >> q;
        c = abs(x - p);
        d = abs(y - q);
        if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
          cout << p << " " << q << endl;
          return 0;
        } else {
          x++;
          y += 2;
          cout << x << " " << y << endl;
          cin >> p >> q;
          c = abs(x - p);
          d = abs(y - q);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << p << " " << q << endl;
            return 0;
          } else {
            x -= 2;
            y--;
            cout << x << " " << y << endl;
            cin >> p >> q;
            x += 2;
            y--;
            cout << x << " " << y << endl;
            return 0;
          }
        }
      }
    }
  } else {
    if (f == 0) {
      v = DFS2(a, b, n / 2, m / 2);
      cout << v[v.size() - 1].first << " " << v[v.size() - 1].second << endl;
      for (i = (long long)v.size() - 1; i >= 0; i--) {
        cin >> p >> q;
        cout << v[i].first << " " << v[i].second << endl;
      }
    } else {
      if (aa <= dd) {
        v = DFS2(a, b, n / 2, m / 2);
        cout << v[v.size() - 1].first << " " << v[v.size() - 1].second << endl;
        if (v[v.size() - 1].first == a && v[v.size() - 1].second == b) {
          return 0;
        }
        for (i = (long long)v.size() - 2; i >= 0; i--) {
          cin >> p >> q;
          cout << v[i].first << " " << v[i].second << endl;
          if (p == v[i].first && q == v[i].second) {
            return 0;
          }
        }
      } else {
        v = DFS2(a, b, n / 2 + 1, m / 2);
        p = x;
        q = y;
        x = a;
        y = b;
        for (i = (long long)v.size() - 1; i >= 0; i--) {
          c = abs(x - p);
          d = abs(y - q);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << p << " " << q << endl;
            return 0;
          } else {
            cout << v[i].first << " " << v[i].second << endl;
            cin >> p >> q;
            x = v[i].first;
            y = v[i].second;
          }
        }
        c = abs(x - p);
        d = abs(y - q);
        if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
          cout << p << " " << q << endl;
          return 0;
        } else {
          x -= 2;
          y++;
          cout << x << " " << y << endl;
          cin >> p >> q;
          c = abs(x - p);
          d = abs(y - q);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << p << " " << q;
            return 0;
          } else {
            x += 2;
            y++;
            cout << x << " " << y << endl;
            cin >> p >> q;
            x--;
            y -= 2;
            cout << x << " " << y << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
long long modInv(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  long long res = (x % m + m) % m;
  return res;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long mpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long p = sqrt(n);
  for (int i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
