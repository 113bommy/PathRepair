#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
 long long int a,b,c;
      
  cin >> a>>b>>c;
  
  long long int d =(a%2)*(b%2)*(c%2)*min({a*b,c*b,a*c});

  
  cout << d << endl;
}
