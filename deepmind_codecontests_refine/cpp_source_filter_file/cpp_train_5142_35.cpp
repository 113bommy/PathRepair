#include <bits/stdc++.h>
using namespace std;
const int INF = 1E9 + 7;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
vector<string> v;
string nr(int x) { return string(1, '0' + x); }
int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  v.push_back("9??>>??0");
  for (int k = (0); k <= (8); ++k)
    v.push_back(nr(k) + "??<>" + nr(k + 1) + "0");
  v.push_back("??<>1");
  for (int k = (0); k <= (9); ++k)
    v.push_back("?" + nr(k) + ">>" + nr(k) + "?");
  v.push_back("9?>>??");
  for (int k = (0); k <= (8); ++k) v.push_back(nr(k) + "?<>" + nr(k + 1));
  v.push_back(">>?");
  for (__typeof((v).begin()) i = ((v).begin()); i != (v).end(); ++i)
    cout << *i << endl;
  return 0;
}
