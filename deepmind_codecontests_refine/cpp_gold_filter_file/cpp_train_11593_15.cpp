#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  short negative = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  x *= negative;
}
inline void write(long long x) {
  static long long sta[35];
  long long top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
  puts("");
}
bool prime(int n) {
  if (n == 0 || n == 1) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
const long long power(int n, int k) {
  long long t = 1;
  for (int i = 0; i < (int)(k); i++) t *= n;
  return t;
}
const string turn2(int n) {
  string s = "";
  while (n != 0) {
    s += (char)(n % 2 + '0');
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
const string turn16(int n) {
  string s = "";
  while (n != 0) {
    if (n % 16 > 9)
      s += (char)('A' + n % 16 - 10);
    else
      s += (char)('0' + n % 16);
    n /= 16;
  }
  reverse(s.begin(), s.end());
  return s;
}
const long long quickpower(int n, int k) {
  if (k == 1) return n;
  if (k % 2 == 1)
    return n * quickpower(n, k / 2) * quickpower(n, k / 2);
  else
    return quickpower(n, k / 2) * (quickpower(n, k / 2));
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
struct team {
  int score;
  int in, out, game;
  string name;
} t[5], g[5];
map<string, int> mp;
vector<pair<int, int> > ans;
bool less1(const team a, const team b) {
  if (a.score != b.score) {
    return a.score >= b.score;
  } else {
    if ((a.in - a.out) != (b.in - b.out)) {
      return (a.in - a.out) >= (b.in - b.out);
    } else {
      if (a.in != b.in) {
        return a.in >= b.in;
      } else {
        return a.name <= b.name;
      }
    }
  }
}
bool less2(pair<int, int> a, pair<int, int> b) {
  if ((a.first - a.second) != (b.first - b.second)) {
    return (a.first - a.second) <= (b.first - b.second);
  } else {
    if (a.second != b.second) {
      return a.second <= b.second;
    }
  }
}
bool good(int c, int d, int a, int b) {
  for (int i = 1; i < 5; i++) {
    g[i] = t[i];
  }
  string l = t[a].name;
  g[a].score += 3;
  g[a].in += c;
  g[a].out += d;
  g[b].in += d;
  g[b].out += c;
  sort(g + 1, g + 5, less1);
  for (int i = 1; i <= 2; i++) {
    if (g[i].name == l) {
      return 1;
    }
  }
  return 0;
}
int main() {
  int l = 1;
  for (int i = 0; i < (int)(5); i++) {
    string a, b;
    cin >> a >> b;
    int c, d;
    scanf("%d:%d", &c, &d);
    if (c > d) {
      if (!mp[a]) {
        mp[a] = l;
        t[l].score += 3;
        t[l].in += c;
        t[l].out += d;
        t[l].name = a;
        t[l].game++;
        l++;
      } else {
        t[mp[a]].score += 3;
        t[mp[a]].in += c;
        t[mp[a]].out += d;
        t[mp[a]].game++;
      }
      if (!mp[b]) {
        mp[b] = l;
        t[l].in += d;
        t[l].out += c;
        t[l].name = b;
        t[l].game++;
        l++;
      } else {
        t[mp[b]].score += 0;
        t[mp[b]].in += d;
        t[mp[b]].out += c;
        t[mp[b]].game++;
      }
    }
    if (c == d) {
      if (!mp[a]) {
        mp[a] = l;
        t[l].score += 1;
        t[l].in += c;
        t[l].out += d;
        t[l].name = a;
        t[l].game++;
        l++;
      } else {
        t[mp[a]].score += 1;
        t[mp[a]].in += c;
        t[mp[a]].out += d;
        t[mp[a]].game++;
      }
      if (!mp[b]) {
        mp[b] = l;
        t[l].score += 1;
        t[l].in += d;
        t[l].out += c;
        t[l].name = b;
        t[l].game++;
        l++;
      } else {
        t[mp[b]].score += 1;
        t[mp[b]].in += d;
        t[mp[b]].out += c;
        t[mp[b]].game++;
      }
    }
    if (d > c) {
      if (!mp[a]) {
        mp[a] = l;
        t[l].score += 0;
        t[l].in += c;
        t[l].out += d;
        t[l].name = a;
        t[l].game++;
        l++;
      } else {
        t[mp[a]].score += 0;
        t[mp[a]].in += c;
        t[mp[a]].out += d;
        t[mp[a]].game++;
      }
      if (!mp[b]) {
        mp[b] = l;
        t[l].score += 3;
        t[l].in += d;
        t[l].out += c;
        t[l].name = b;
        t[l].game++;
        l++;
      } else {
        t[mp[b]].score += 3;
        t[mp[b]].in += d;
        t[mp[b]].out += c;
        t[mp[b]].game++;
      }
    }
  }
  int a = mp["BERLAND"], b = 0;
  for (int i = 1; i <= 4; i++) {
    if (i != a && t[i].game == 2) {
      b = i;
      break;
    }
  }
  for (int i = 1; i <= 30; i++)
    for (int j = 0; j < (int)(i); j++) {
      if (good(i, j, a, b)) {
        ans.push_back(pair<int, int>(i, j));
      }
    }
  if (ans.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  sort(ans.begin(), ans.end(), less2);
  cout << ans[0].first << ":" << ans[0].second << endl;
  return 0;
}
