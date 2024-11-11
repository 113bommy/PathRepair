#include<iostream>
using namespace std;
int main(){
	int a, b, c, d; cin >> a >> b >> c >> d;
	int e, f, g, h; cin >> e >> f >> g >> h;
	int hi = a*e + (a / 10)*g + b*f + (b / 20)*h;
	int k = c*e + (c / 10)*g + d*f + (d / 20)*h;
	if (hi > k)cout << "hiroshi\n";
	else if (hi < k)cout << "kenjiro\n";
	else cout << "even\n";
}