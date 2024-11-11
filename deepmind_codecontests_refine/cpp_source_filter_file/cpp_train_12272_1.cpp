#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

string func(int s, int l){
	double h = s*30.0 + l/2.0, m = l*6;
     
    int ang = abs(h - m);
    if(ang > 180) ang = 360 - ang;
    if(0 <= ang && ang < 30) {
      return "alert";
    }
    else if(90 <= ang && ang <= 180) {
      return "safe";
    }
    else return "warning";
}
 
int main() {
	int n, s, l; cin >> n;
	while(n--) {
		cin >> s >> c >> l;
		cout << func(s, l) << endl;
	}
  	return 0;
}