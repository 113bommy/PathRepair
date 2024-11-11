#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int x[10];
	for(int i = 0; i < 10; i++){
		cin >> x[i];
	}
	sort(x,x + 10);
	cout << x[9] << endl; << x[8] << endl; << x[7] << endl;
	return 0;
}