#include <iostream>
using namespace std;

int main(){
	int a ,b ,c;
	cin >> a >> b >> c;
	if(a + b < c){
		cout << "NA" << endl;
		return 0;
	}
	if(a >= c){
		cout << 0 << endl;
		return 0;
	}
	cout << c-a << endl;
	return 0;
}