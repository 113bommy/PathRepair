#include<iostream>
using namespace std;

int main(){
	int L,A,B,C,D,x,y;
	cin >>L >>A >>B >>C >>D;
	if(A%C==0)
		x=A/C;
		else
			x=A/C+1;
	if(B%D==0)
		y=B/D;
		else
			y=B/D+1;
	if(x<y)
		x=y;
		
	cout << L-x <<endl;

	return 0;
}