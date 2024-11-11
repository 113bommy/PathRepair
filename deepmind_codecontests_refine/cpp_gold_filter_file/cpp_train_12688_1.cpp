#include <bits/stdc++.h>
using namespace std ;

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  const double r = 6378.1;
  double x1,y1,x2,y2;
  double c = M_PI/180.0;
  while(cin >> y1 >> x1 >> y2 >> x2){
    if(y1 == -1 && x1 == -1 && y2 == -1 && x2 == -1) break;
    y1 = y1 * c;
    y2 = y2 * c;
    double d = r * acos(sin(y1) * sin(y2) + cos(y1) * cos(y2) * cos(x1*c - x2*c));
    cout << (int)(d + 0.5) << endl;
  }
  return 0;
}