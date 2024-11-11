#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  cout << n%111==0 ? n : (n/111+1)*111;
  return 0;
}