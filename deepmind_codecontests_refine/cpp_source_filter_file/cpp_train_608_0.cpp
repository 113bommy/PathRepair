#include <iostream>

using namespace std;

int main() {
  int a[4], b, hit, blow, i, j;
  while (cin >> a[0]) {
    h = 0, blow = 0;
    for (i = 1; i < 4; i++) {
      cin >> a[i];
    }
    for (i = 0; i < 4; i++) {
      cin >> b;
      for (j = 0; j < 4; j++) {
	if (a[j] == b) {
	  if (i == j) {
	    hit++;
	  }
	  else {
	    blow++;
	  }
	}
      }
    }
    cout << hit << ' ' << blow << endl;
  }
  return 0;
}