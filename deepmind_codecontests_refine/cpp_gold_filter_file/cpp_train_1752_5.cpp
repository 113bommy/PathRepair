#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,k;
int main(){
  cin >> a >> b >> c >> k;
  cout << (a-b)*(1-k%2*2) << endl;
  return 0;
}
  