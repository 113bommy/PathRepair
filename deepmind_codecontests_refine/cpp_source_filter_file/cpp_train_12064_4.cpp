#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  long long  ave = 0;
  long long  a;
  for(int i = 0 ; i < n ; i++ ){
    cin >> a;
    ave += a;
   }
  cout << (int)(ave/m) << endl;
  return 0;
}