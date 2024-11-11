#include <iostream>
#define MAX 196470

using namespace std;

int main(void){

  int n;
  cin >> n;

 while(n--){
   int y,m,d;
   cin >> y >> m >> d;
   y--; m--; d--;
   int day = 0;
   day += ( 20*5 + 19*5) * y;
   day += (y/3) * 5;
   day += m * 20;
   if( (y + 1) % 3 != 0 ) day -= (m/2);
   day += d;
   cout << MAX - day << endl;
 }
}