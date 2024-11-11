#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string c;
  string a;
  cin >> c;
  cin >> a;
  map<int, char> mp;
  int nc = 0, na = 0, nb = 0, nn = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] == '1' && a[i] == '1') {
      nb++;
      mp.insert({i, 'b'});
    } else {
      if (a[i] == '1') {
        na++;
        mp.insert({i, 'a'});
      } else {
        if (c[i] == '1') {
          nc++;
          mp.insert({i, 'c'});
        } else {
          nn++;
          mp.insert({i, 'n'});
        }
      }
    }
  }
  int anc = 0, anb = 0, ana = 0, ann = 0;
  if (na == n || nc == n || (na == 0 && nc == 0 && nb % 2 != 0) ||
      (max(na, nc) - nn > min(na, nc) + nb)) {
    cout << -1;
    return 0;
  }
  if (nc >= na) {
    if (nb - (nc - na) >= 0 && (nb - (nc - na)) % 2 == 0) {
      anc = nc;
      anb = (nb - (nc - na)) / 2;
      ann = nn / 2;
    } else if ((nb - (nc - na)) % 2 != 0) {
      anc = nc - 1;
      ann = 1;
      anb = (nb - (nc - 1 - na)) / 2;
      ann += (nn - 1) / 2;
    } else if (nb - (nc - na) < 0) {
      anc = na + nb;
      ann = nc - anc;
      ann += (nn - ann) / 2;
    }
  } else {
    if (nb - (na - nc) >= 0 && (nb - (na - nc)) % 2 == 0) {
      anc = nc;
      ann = nn / 2;
      anb = (nb - (na - nc)) / 2 + (na - nc);
    } else if ((nb - (na - nc)) % 2 != 0) {
      anc = nc;
      anb = (nb - (na - 1 - nc)) / 2 + na - nc - 1;
      ann = (nn - 1) / 2;
      ana = 1;
    } else if (nb - (na - nc) < 0) {
      anc = nc;
      anb = nb;
      ana = na - anc - anb;
      ann = (nn - ana) / 2;
    }
  }
  for (auto i = mp.begin(); i != mp.end(); i++) {
    if (i->second == 'c' && anc > 0) {
      cout << i->first + 1 << " ";
      anc--;
    }
    if (i->second == 'b' && anb > 0) {
      cout << i->first + 1 << " ";
      anb--;
    }
    if (i->second == 'n' && ann > 0) {
      cout << i->first + 1 << " ";
      ann--;
    }
    if (i->second == 'a' && ana > 0) {
      cout << i->first + 1 << " ";
      ana--;
    }
  }
}
