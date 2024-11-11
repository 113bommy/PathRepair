#include <bits/stdc++.h>
using namespace std;
int t, k, l;
string s, a, b;
bool v[30];
int p[30];
void fill() {
  int i1 = 0, i2 = 0;
  while (i1 < k && i2 < k) {
    if (p[i1] != -1)
      i1++;
    else if (v[i2])
      i2++;
    else {
      p[i1] = i2;
      v[i2] = true;
      i1++;
      i2++;
    }
  }
}
bool search(int now, int st) {
  if (now >= l) {
    fill();
    return true;
  }
  int x = s[now] - 'a', xa = a[now] - 'a', xb = b[now] - 'a';
  if (p[x] != -1) {
    if (st == 1) {
      if (p[x] > xa) {
        fill();
        return true;
      } else if (p[x] == xa)
        return search(now + 1, 1);
      else
        return false;
    } else if (st == 2) {
      if (p[x] < xb) {
        fill();
        return true;
      } else if (p[x] == xb)
        return search(now + 1, 2);
      else
        return false;
    } else if (st == 3) {
      if (p[x] > xa && p[x] < xb) {
        fill();
        return true;
      } else if (p[x] == xa && p[x] == xb)
        return search(now + 1, 3);
      else if (p[x] == xa && xa < xb)
        return search(now + 1, 1);
      else if (p[x] == xb && xa < xb)
        return search(now + 1, 2);
      else
        return false;
    }
    return false;
  } else {
    if (st == 3) {
      for (int i = xa + 1; i < xb; i++)
        if (!v[i]) {
          p[x] = i;
          v[i] = true;
          fill();
          return true;
        }
      if (xa == xb) {
        if (!v[xa]) {
          v[xa] = true;
          p[x] = xa;
          if (search(now + 1, 3)) return true;
          v[xa] = false;
          p[x] = -1;
        }
      } else {
        if (!v[xa]) {
          v[xa] = true;
          p[x] = xa;
          if (search(now + 1, 1)) return true;
          v[xa] = false;
          p[x] = -1;
        }
        if (!v[xb]) {
          v[xb] = true;
          p[x] = xb;
          if (search(now + 1, 2)) return true;
          v[xb] = false;
          p[x] = -1;
        }
      }
      return false;
    } else if (st == 1) {
      for (int i = xa + 1; i < k; i++)
        if (!v[i]) {
          p[x] = i;
          v[i] = true;
          fill();
          return true;
        }
      if (!v[xa]) {
        v[xa] = true;
        p[x] = xa;
        if (search(now + 1, 1)) return true;
        v[xa] = false;
        p[x] = -1;
      }
      return false;
    } else if (st == 2) {
      for (int i = 0; i < xb; i++)
        if (!v[i]) {
          p[x] = i;
          v[i] = true;
          fill();
          return true;
        }
      if (!v[xb]) {
        v[xb] = true;
        p[x] = xb;
        if (search(now + 1, 2)) return true;
        v[xb] = false;
        p[x] = -1;
      }
      return false;
    }
    return false;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> k >> s >> a >> b;
    l = s.size();
    for (int i = 0; i < k; i++) {
      p[i] = -1;
      v[i] = false;
    }
    if (!search(0, 3))
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i = 0; i < k; i++) cout << (char)('a' + p[i]);
      cout << "\n";
    }
  }
}
