#include <iostream>
#include <stdio.h>
using namespace std;
 int an[4][2],n,i,j;
 int main() {
  double ey[2];
  while(cin >> ey[0] >> ey[1]) {
	  for (i=0;i<2;i++) {
		  if (ey[i]>=1.1) j=0;
		  if (ey[i]>=0.6 && ey[i]<1.1) j=1;
		  if (ey[i]>=0.2 && ey[i]<0.6) j=2;
		  if (ey[i]<0.2) j=3;
		  an[j][i]++;
	  }
   }
  for (i=0;i<4;i++) cout << an[i][0] << ' ' << an[i][1] << endl;
  return 0;
 }