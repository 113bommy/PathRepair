#include<iostream>
#include<algorithm>
using namespace std;


struct rect {
  double leftX, leftY;
  double rightX, rightY;
};

int main() {
  rect a, b;

  while(cin >> a.leftX >> a.leftY >> a.rightX >> a.rightY >> b.leftX >> b.leftY >> b.rightX >> b.rightY) {
    if(b.rightX < a.leftX || a.rightX < b.leftX || b.rightY < a.leftY || a.rightY < b.leftY) {
      cout << "NO" << endl;
    }else {
      cout << "YES" << endl;
    }
  }
  return 0;
}