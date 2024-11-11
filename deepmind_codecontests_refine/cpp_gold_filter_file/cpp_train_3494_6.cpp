#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, one, two;
  cin >> n;
  long long int a, b, c;
  long long int x, maxer = 0;
  long long int pos1 = 0;
  long long int pos2 = 0;
  map<pair<long long int, long long int>,
      vector<pair<long long int, long long int>>>
      m;
  map<pair<long long int, long long int>,
      vector<pair<long long int, long long int>>>::iterator it;
  for (int i = 0; i < n; i++) {
    pair<long long int, long long int> p;
    cin >> a >> b >> c;
    x = min(min(a, b), c);
    if (x > maxer) {
      maxer = x;
      pos1 = i + 1;
    }
    if (a == b && b == c) {
      p = make_pair(a, b);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(c, i + 1));
    } else if (a == b) {
      p = make_pair(a, b);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(c, i + 1));
      one = min(a, c);
      two = max(a, c);
      p = make_pair(one, two);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(b, i + 1));
    } else if (a == c) {
      p = make_pair(a, c);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(b, i + 1));
      one = min(a, b);
      two = max(a, b);
      p = make_pair(one, two);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(c, i + 1));
    } else if (b == c) {
      p = make_pair(b, c);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(a, i + 1));
      one = min(a, c);
      two = max(a, c);
      p = make_pair(one, two);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(b, i + 1));
    } else {
      one = min(a, b);
      two = max(a, b);
      p = make_pair(one, two);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(c, i + 1));
      one = min(a, c);
      two = max(a, c);
      p = make_pair(one, two);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(b, i + 1));
      one = min(b, c);
      two = max(b, c);
      p = make_pair(one, two);
      it = m.find(p);
      if (it == m.end()) m[p];
      m[p].push_back(make_pair(a, i + 1));
    }
  }
  for (it = m.begin(); it != m.end(); it++) {
    long long int post1, post2;
    if (it->second.size() == 1) continue;
    if (it->second[0] > it->second[1]) {
      one = it->second[0].first;
      two = it->second[1].first;
      post1 = it->second[0].second;
      post2 = it->second[1].second;
    } else {
      one = it->second[1].first;
      two = it->second[0].first;
      post1 = it->second[1].second;
      post2 = it->second[0].second;
    }
    for (int u = 2; u < (int)it->second.size(); u++) {
      if (it->second[u].first > one) {
        two = one;
        one = it->second[u].first;
        post2 = post1;
        post1 = it->second[u].second;
      } else if (it->second[u].first > two) {
        two = it->second[u].first;
        post2 = it->second[u].second;
      }
    }
    x = min(it->first.first, (one + two));
    if (x > maxer) {
      maxer = x;
      pos1 = post1;
      pos2 = post2;
    }
  }
  if (pos2 == 0) {
    cout << 1 << endl;
    cout << pos1 << endl;
  } else {
    cout << 2 << endl;
    cout << pos1 << " " << pos2 << endl;
  }
  return 0;
}
