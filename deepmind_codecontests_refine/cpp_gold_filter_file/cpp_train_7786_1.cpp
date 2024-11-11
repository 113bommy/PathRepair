#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll s,x,y;
  ll max = 1000000000;
  cin >> s;
  x = (max-s%max)%max;
  y = (s+x)/max;
  cout << "0 0 1000000000 1 "<< x << " "<< y << endl;
}
  
  
