#include <bits/stdc++.h>
using namespace std;
struct male {
  const string adjective = "lios";
  const string noun = "etr";
  const string verb = "initis";
};
struct female {
  const string adjective = "liala";
  const string noun = "etra";
  const string verb = "inites";
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, t;
  male m;
  female f;
  getline(cin, s);
  s.push_back(' ');
  int n = s.size();
  vector<string> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      v.emplace_back(t);
      t.clear();
    } else {
      t += s[i];
    }
  }
  if (v.size() == 1) {
    if (v[0].size() >= m.adjective.size() and
        v[0].substr(v[0].size() - m.adjective.size()) == m.adjective) {
      cout << "YES\n";
      return 0;
    }
    if (v[0].size() >= f.adjective.size() and
        v[0].substr(v[0].size() - f.adjective.size()) == f.adjective) {
      cout << "YES\n";
      return 0;
    }
    if (v[0].size() >= m.noun.size() and
        v[0].substr(v[0].size() - m.noun.size()) == m.noun) {
      cout << "YES\n";
      return 0;
    }
    if (v[0].size() >= f.noun.size() and
        v[0].substr(v[0].size() - f.noun.size()) == f.noun) {
      cout << "YES\n";
      return 0;
    }
    if (v[0].size() >= m.verb.size() and
        v[0].substr(v[0].size() - m.verb.size()) == m.verb) {
      cout << "YES\n";
      return 0;
    }
    if (v[0].size() >= f.verb.size() and
        v[0].substr(v[0].size() - f.verb.size()) == f.verb) {
      cout << "YES\n";
      return 0;
    }
    cout << "NO\n";
    return 0;
  } else {
    int nmi = -1, nfi = -1;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].size() < m.noun.size() and v[i].size() < f.noun.size()) continue;
      if (v[i].substr(v[i].size() - m.noun.size()) == m.noun) {
        nmi = i;
        break;
      }
      if (v[i].substr(v[i].size() - f.noun.size()) == f.noun) {
        nfi = i;
        break;
      }
    }
    if (nmi < 0 and nfi < 0) {
      cout << "NO\n";
      return 0;
    }
    if (nmi >= 0) {
      bool fg = true;
      for (int i = 0; i < nmi; i++) {
        fg &= (v[i].size() >= m.adjective.size());
        if (!fg) {
          break;
        }
        fg &= (v[i].substr(v[i].size() - m.adjective.size(),
                           m.adjective.size()) == m.adjective);
        if (!fg) {
          break;
        }
      }
      for (int i = (nmi + 1); i < v.size(); i++) {
        fg &= (v[i].size() >= m.verb.size());
        if (!fg) {
          break;
        }
        fg &=
            (v[i].substr(v[i].size() - m.verb.size(), m.verb.size()) == m.verb);
        if (!fg) {
          break;
        }
      }
      cout << (fg ? "YES\n" : "NO\n");
      return 0;
    }
    if (nfi >= 0) {
      bool fg = true;
      for (int i = 0; i < nfi; i++) {
        fg &= (v[i].size() >= f.adjective.size());
        if (!fg) {
          break;
        }
        fg &= (v[i].substr(v[i].size() - f.adjective.size(),
                           f.adjective.size()) == f.adjective);
        if (!fg) {
          break;
        }
      }
      for (int i = (nfi + 1); i < v.size(); i++) {
        fg &= (v[i].size() >= f.verb.size());
        if (!fg) {
          break;
        }
        fg &=
            (v[i].substr(v[i].size() - f.verb.size(), f.verb.size()) == f.verb);
        if (!fg) {
          break;
        }
      }
      cout << (fg ? "YES\n" : "NO\n");
      return 0;
    }
  }
}
