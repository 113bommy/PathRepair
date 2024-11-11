#include <iostream>
using namespade std;
int main(){
  int h, m = -1, c = 0, n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> h;
	if(m <= h){
		c++;m=h;
    }
  }
  cout << c;
  return 0;
}