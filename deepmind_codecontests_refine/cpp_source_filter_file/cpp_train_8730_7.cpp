#include <iostream>
using namespace std;
int h[51];
int main() {
 int a,b,c,d,n,j=0,m;
 for (m=0; m<10000; m++) {
	 a=m/1000; b=(m-a*1000)/100;
	 c=(m-a*1000-b*100)/10; d=m-a*1000-b*100-c*10;
     h[a+b+c+d]++;
 }
 while(cin >> n) cout << h[n] << endl;
 return 0;