#include <iostream>
#include <algorithm>
using namespace std;
int n, dx, dy;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x = 0, y = 0, px = 0, py = 0;
		while(cin >> dx >> dy, dx | dy) {
			x += dx, y += dy;
			if((10000LL * (px * px + py * py) + px) < 10000LL * (x * x + y * y) + x)) px = x, py = y;
		}
		cout << px << ' ' << py << endl;
	}
}