#include<iostream>
using namespace std;
int main(){
	int a, b, c, d; cin >> a >> b >> c >> d;
	int e, f, g, h; cin >> e >> f >> g >> h;
	int h = a*e + (a / 10)*g + b*f + (b / 10)*h;
	int k = c*e + (c / 10)*g + d*f + (d / 10)*h;
	if (h > k)cout << "hiroshi\n";
	else if (h < k)cout << "kenjiro\n";
	else cout << "even\n";
}