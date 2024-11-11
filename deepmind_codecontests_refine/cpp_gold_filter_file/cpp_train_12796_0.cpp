#include <iostream>
#include <cmath>
#define pow2(x) ((x)*(x))
using namespace std;
struct three_d{
  double x, y, z;
} stars[31];
int n;


double distancex(three_d from, int to){
  return pow2(from.x-stars[to].x) + pow2(from.y-stars[to].y) + pow2(from.z-stars[to].z);
}

int main(){
  while((cin >> n), n){
    for(int i=0; i<n; i++) cin >> stars[i].x >> stars[i].y >> stars[i].z;
    double move = 0.5, maxdis;
    three_d now = {0, 0, 0};
    int moveto = 0, i;
    while(move > 0.000000001){
      for(int j=0;j<1000;j++){
	now.x = now.x * (1-move) + stars[moveto].x * move;
	now.y = now.y * (1-move) + stars[moveto].y * move;
	now.z = now.z * (1-move) + stars[moveto].z * move;
	moveto = 0; maxdis = 0;
	for(i=0; i<n; i++)
	  if(distancex(now, i) > maxdis){
	    maxdis = distancex(now, i);
	    moveto = i;
	  }
      }
      move /= 2;
    }
    printf("%.5lf\n", sqrt(maxdis));
  }
}