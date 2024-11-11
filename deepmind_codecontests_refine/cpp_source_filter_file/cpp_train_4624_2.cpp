#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<long long, pair<int, int> > > v(n);
  int re = 0;
  for (int i = 0; i < (n); i++) {
    int t, tt;
    cin >> t >> tt;
    v[i] = make_pair((long long)abs(t) + abs(tt), make_pair(t, tt));
    re += 2;
    if (t == 0 || tt == 0)
      re += 2;
    else
      re += 4;
  }
  sort((v).begin(), (v).end());
  cout << re << endl;
  for (int i = 0; i < (((int)(v).size())); i++) {
    int t = v[i].second.first, tt = v[i].second.second;
    if (t == 0) {
      if (tt > 0) {
        cout << "1 " << abs(tt) << " U" << endl;
        cout << "2" << endl;
        cout << "1 " << abs(tt) << " D" << endl;
        cout << "3" << endl;
      } else {
        cout << "1 D " << abs(tt) << " D" << endl;
        cout << "2" << endl;
        cout << "1 U " << abs(tt) << " U" << endl;
        cout << "3" << endl;
      }
    } else if (tt == 0) {
      if (t > 0) {
        cout << "1 " << abs(t) << " R" << endl;
        cout << "2" << endl;
        cout << "1 " << abs(t) << " L" << endl;
        cout << "3" << endl;
      } else {
        cout << "1 " << abs(t) << " L" << endl;
        cout << "2" << endl;
        cout << "1 " << abs(t) << " R" << endl;
        cout << "3" << endl;
      }
    } else {
      if (t > 0) {
        cout << "1 " << abs(t) << " R" << endl;
      } else {
        cout << "1 " << abs(t) << " L" << endl;
      }
      if (tt > 0) {
        cout << "1 " << abs(tt) << " U" << endl;
      } else {
        cout << "1 " << abs(tt) << " D" << endl;
      }
      cout << "2" << endl;
      if (t > 0) {
        cout << "1 " << abs(t) << " L" << endl;
      } else {
        cout << "1 " << abs(t) << " R" << endl;
      }
      if (tt > 0) {
        cout << "1 " << abs(tt) << " D" << endl;
      } else {
        cout << "1 " << abs(tt) << " U" << endl;
      }
      cout << "3" << endl;
    }
  }
  return 0;
}
