#include <bits/stdc++.h>
using namespace std;
int n, k;
long int a[100000 + 5];
set<pair<long int, long> > st1, st2;
set<pair<long int, long int> >::iterator it1, it2, ans;
pair<long int, long int> p;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (long int i = 0; i < k; i++) {
    cin >> a[i];
    if (st1.size() == 0) {
      st1.insert({a[i], 1});
      st2.insert({1, a[i]});
    } else {
      it1 = st1.lower_bound({a[i], -INFINITY});
      if ((*it1).first == a[i]) {
        it2 = st2.lower_bound({(*it1).second, (*it1).first});
        p = {(*it1).first, (*it1).second + 1};
        st1.erase(it1);
        st1.insert(p);
        p = {(*it2).first + 1, (*it2).second};
        st2.erase(it2);
        st2.insert(p);
      } else {
        st1.insert({a[i], 1});
        st2.insert({1, a[i]});
      }
    }
  }
  ans = st2.lower_bound({2, -INFINITY});
  if (ans == st2.begin())
    cout << "Nothing" << endl;
  else {
    ans--;
    cout << (*ans).second << endl;
  }
  for (long int i = k; i < n; i++) {
    cin >> a[i];
    it1 = st1.lower_bound({a[i], -INFINITY});
    if ((*it1).first == a[i]) {
      it2 = st2.lower_bound({(*it1).second, (*it1).first});
      p = {(*it1).first, (*it1).second + 1};
      st1.erase(it1);
      st1.insert(p);
      p = {(*it2).first + 1, (*it2).second};
      st2.erase(it2);
      st2.insert(p);
    } else {
      st1.insert({a[i], 1});
      st2.insert({1, a[i]});
    }
    it1 = st1.lower_bound({a[i - k], -INFINITY});
    if ((*it1).second == 0) {
      it2 = st2.lower_bound({(*it1).second, (*it1).first});
      st1.erase(it1);
      st2.erase(it2);
    } else {
      it2 = st2.lower_bound({(*it1).second, (*it1).first});
      p = {(*it1).first, (*it1).second - 1};
      st1.erase(it1);
      st1.insert(p);
      p = {(*it2).first - 1, (*it2).second};
      st2.erase(it2);
      st2.insert(p);
    }
    ans = st2.lower_bound({2, -INFINITY});
    if (ans == st2.begin())
      cout << "Nothing" << endl;
    else {
      ans--;
      cout << (*ans).second << endl;
    }
  }
  return 0;
}
