#include <iostream>
using namespace std;

int main(){
  long long int a,b,x;
  cin >> a >> b >> x;
  cout << ((a==0)?(b/x+1):(b/x-(a-1)/x)) << endl;

  return 0;
}
