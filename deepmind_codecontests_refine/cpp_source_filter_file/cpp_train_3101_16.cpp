#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll a,b,c; cin >> a >> b >> c;
  ll d=c-a-b;
  if(d>0 && pow((d,2)>4*a*b)) cout << "Yes" << endl;
  else cout << "No" << endl;

}
