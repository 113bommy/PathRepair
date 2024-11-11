#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
// const ll MOD = 1000000007;

int main() {
  int Q;
  cin>>Q;
  multiset<ll> st1,st2;
  st1.insert(-(1e9 + 1));
  st2.insert(1e9 + 1);
  ll res = 0;
  for (int i = 0; i < Q; i++) {
    int c; cin>>c;
    if (c == 1) {
      ll a,b;
      cin>>a>>b;
      res += b;
      ll left = *st1.rbegin();
      ll right = *st2.begin();
      if (left <= a && a <= right) {
        st1.insert(a);
        st2.insert(a);
      } else if (a < left) {
        st1.insert(a);
        st1.insert(a);
        st1.erase(st1.rbegin());
        st2.insert(left);
        res += left - a;
      } else {
        st2.insert(a);
        st2.insert(a);
        st2.erase(st2.begin());
        st1.insert(right);
        res += a - right;
      }
    } else {
      ll kyoku = *st1.rbegin();
      cout<<kyoku<<" "<<res<<endl;
    }
  }
  return 0;
}