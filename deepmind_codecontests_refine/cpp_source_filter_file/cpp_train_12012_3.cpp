#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  map<int, vector<pair<int, int> > > hor, ver;
  map<int, vector<pair<int, int> > >::iterator mit;
  int x1, x2, y1, y2;
  for (int i = 0; i < k; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      ver[x1].push_back(pair<int, int>(y1, 1));
      ver[x2].push_back(pair<int, int>(y2, -1));
    }
    if (y1 == y2) {
      if (x1 > x2) swap(x1, x2);
      hor[y1].push_back(pair<int, int>(x1, 1));
      hor[y2].push_back(pair<int, int>(x2, -1));
    }
  }
  int xorsum = 0;
  map<int, int> h, v;
  map<int, int>::iterator miit;
  for (mit = hor.begin(); mit != hor.end(); ++mit) {
    sort(mit->second.begin(), mit->second.end());
    int layer(0), cut(0), size = mit->second.size() - 1;
    for (int i = 0; i < size; ++i) {
      layer += mit->second[i].second;
      if (layer) cut += mit->second[i + 1].first - mit->second[i].first;
    }
    h[mit->first] = n - cut;
    xorsum ^= n - cut;
  }
  for (mit = ver.begin(); mit != ver.end(); ++mit) {
    sort(mit->second.begin(), mit->second.end());
    int layer(0), cut(0), size = mit->second.size() - 1;
    for (int i = 0; i < size; ++i) {
      layer += mit->second[i].second;
      if (layer) cut += mit->second[i + 1].first - mit->second[i].first;
    }
    v[mit->first] = m - cut;
    xorsum ^= m - cut;
  }
  if ((m - 1 - h.size()) % 2) xorsum ^= n;
  if ((n - 1 - v.size()) % 2) xorsum ^= m;
  if (xorsum) {
    cout << "FIRST\n";
    if (n >= (n ^ xorsum)) {
      int a = n - (n ^ xorsum);
      if (m > 1 && !h.count(m - 1)) {
        cout << 0 << ' ' << m - 1 << ' ' << a << ' ' << m - 1;
        return 0;
      }
      int i = 1;
      for (miit = h.begin(); miit != h.end(); ++miit, ++i) {
        if (i != miit->first) {
          cout << 0 << ' ' << i << ' ' << a << ' ' << i;
          return 0;
        }
      }
    }
    if (m >= (m ^ xorsum)) {
      int a = m - (m ^ xorsum);
      if (n > 1 && !v.count(n - 1)) {
        cout << n - 1 << ' ' << 0 << ' ' << n - 1 << ' ' << a;
        return 0;
      }
      int i = 1;
      for (miit = v.begin(); miit != v.end(); ++mit, ++i) {
        if (i != miit->first) {
          cout << i << ' ' << 0 << ' ' << i << ' ' << a;
          return 0;
        }
      }
    }
    for (miit = h.begin(); miit != h.end(); ++miit) {
      int a = miit->second - (miit->second ^ xorsum);
      if (a >= 0) {
        mit = hor.find(miit->first);
        int i, layer(0), uncut = mit->second.front().first;
        mit->second.push_back(pair<int, int>(n, 0));
        for (i = 0; uncut < a; ++i) {
          layer += mit->second[i].second;
          if (!layer) uncut += mit->second[i + 1].first - mit->second[i].first;
        }
        x2 = mit->second[i].first - uncut + a;
        cout << 0 << ' ' << miit->first << ' ' << x2 << ' ' << miit->first;
        return 0;
      }
    }
    for (miit = v.begin(); miit != v.end(); ++miit) {
      int a = miit->second - (miit->second ^ xorsum);
      if (a >= 0) {
        mit = ver.find(miit->first);
        int i, layer(0), uncut = mit->second.front().first;
        mit->second.push_back(pair<int, int>(m, 0));
        for (i = 0; uncut < a; ++i) {
          layer += mit->second[i].second;
          if (!layer) uncut += mit->second[i + 1].first - mit->second[i].first;
        }
        y2 = mit->second[i].first - uncut + a;
        cout << miit->first << ' ' << 0 << ' ' << miit->first << ' ' << y2;
        return 0;
      }
    }
  } else
    cout << "SECOND";
  return 0;
}
