#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  long long a,b,c;
  cin >> a >> b >> c;
  if(a%2==0||b%2==0||c%2==0) {
    cout << 0 << endl;
  }
  else {
    cout << min({a*b,b*c,c*a}) << endl;
  }
}
