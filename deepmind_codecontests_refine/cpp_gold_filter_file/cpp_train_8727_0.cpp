#include<iostream>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	for (ll h = 1;h <= 3500;h++) {
		for (ll w = 1;w <= 3500;w++) {
			ll t = n * w*h;
			if (4 * h*w - n * w - n * h <= 0) continue;
			if (t % (4 * h*w - n * w - n * h) == 0) {
				printf("%d %d %d\n", h, w, t / (4 * h*w - n * w - n * h));
				return 0;
			}
		}
	}
}
