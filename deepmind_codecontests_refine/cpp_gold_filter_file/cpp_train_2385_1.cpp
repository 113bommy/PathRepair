#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n;
	while (cin >> n&&n != 0) {
		int a[3][2];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) a[i][j] = 0;
		}
		int b, c, d;
		for (int i = 0; i < n; i++) {
			scanf("%d:%d %d", &b, &c, &d);
			if (b < 11) b += 24;
			if (d < c) d += 60;
			int f = d - c;
			int e = b * 60 + c;
			if (e >= 11 * 60 && e < 15 * 60) {
				a[0][0]++;
				if (f <= 8) a[0][1]++;
			}
			if (e >= 18 * 60 && e < 21 * 60) {
				a[1][0]++;
				if (f <= 8) a[1][1]++;
			}
			if (e >= 21 * 60) {
				a[2][0]++;
				if (f <= 8) a[2][1]++;
			}
		}
		if (a[0][0] == 0) {
			cout << "lunch no guest" << endl;
		}
		else {
			cout << "lunch " << (a[0][1] * 100) / a[0][0] << endl;
		}
		if (a[1][0] == 0) {
			cout << "dinner no guest" << endl;
		}
		else {
			cout << "dinner " << (a[1][1] * 100) / a[1][0] << endl;
		}
		if (a[2][0] == 0) {
			cout << "midnight no guest" << endl;
		}
		else {
			cout << "midnight " << (a[2][1] * 100) / a[2][0] << endl;
		}
	}
}