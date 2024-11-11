#include <iostream>
using namespace	std;

int main() {
  int m, n;
  int num;

  while(1) {
    cin >> m >> n;
    if(m == 0)
      break;

    int count = 0;
    for(int i = m; i <= n; i++) {
      num = i;
      while(1) {
        if(num == 1) {
          count++;
          break;
        }
        if(num % 2 == 0)
          num =	num / 2;
        else if(num % 3 == 0)
          num =	num / 3;
        else if(num % 5 == 0)
          num = num / 5;
	else
          break;
      }
    }
    cout << count << endl;
  }
  return 0;
}


