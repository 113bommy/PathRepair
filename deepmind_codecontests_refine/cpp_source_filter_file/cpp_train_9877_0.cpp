#include<iostream>
#include<algorithm>
#include<math>
using namespace std;

double ESP = 1e-10;

struct point {
  double x, y;
};

int main() {
  point P[4];

  while(true){
    for(int i = 0; i < 4; i++){
      cin >> P[i].x >> P[i].y;
    }
    if(cin.eof()) break;

    if(abs((P[1].y - P[0].y)*(P[3].y - P[2].y) + (P[3].x - P[2].x)*(P[1].x - P[0].x)) < ESP) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

    return 0;
}