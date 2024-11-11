#include <iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  cout << max({2*a-1, 2*b-1, a+b});
  return 0;
}
