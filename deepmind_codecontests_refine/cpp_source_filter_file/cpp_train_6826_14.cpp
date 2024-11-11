#include <bits/stdc++.h>
using namespace std;
struct name {
  string handle;
  int su, unsu, a, b, c, d, e;
} temp;
int main() {
  int n;
  cin >> n;
  vector<pair<int, string> > v;
  for (int i = 0; i < n; i++) {
    cin >> temp.handle >> temp.su >> temp.unsu >> temp.a >> temp.b >> temp.c >>
        temp.d >> temp.e;
    int tot = 0;
    tot = (temp.su * 50) - (temp.unsu * 25) + temp.a + temp.b + temp.c +
          temp.d + temp.e;
    v.push_back(make_pair(tot, temp.handle));
  }
  sort(v.begin(), v.end());
  cout << v[v.size() - 1].second << endl;
  return 0;
}
