#include <iostream>
using namespace std;
int main(){
  int x;
  cin >> x;
  int i=1;
  while((360*i)%x!=0){
    i++;
  }
  cout << (360*i)/x;
  return 0;
}
