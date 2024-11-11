# include <iostream>
using namespace std;
typedef long long ll;

int main(void){
  ll n, m;
  cin >> n>> m;
  if (abs(n-m) <= 1) cout << "Brown" << endl;
  else cout << "Alice" << endl;
}