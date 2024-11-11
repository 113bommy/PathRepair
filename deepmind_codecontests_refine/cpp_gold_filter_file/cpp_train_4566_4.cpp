#include <iostream>
using namespace std;

int main(){
	int W, a, b;
	cin >> W >> a >> b;
	if(abs(a-b)<=W) cout << 0 << endl;
	else cout << abs(a-b)-W << endl;
}
