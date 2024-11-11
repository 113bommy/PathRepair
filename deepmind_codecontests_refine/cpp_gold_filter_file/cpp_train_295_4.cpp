#include<iostream>
using namespace std;
int main(){
	int a, b, c, rect = 0, rhom = 0;
	char d;
	while(cin >> a >> d >> b >> d >> c){
		if( a * a + b * b == c * c ) rect++;
		else if( a == b ) rhom++;
	}
	cout << rect << endl << rhom << endl;
}