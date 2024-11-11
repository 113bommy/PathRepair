#include <iostream>
#include <cstring>
using namespace std;
int n;
char t[256][256];
int d[4][2] = {
	{-1, 0},
	{-1. -1},
	{0, -1},
	{1, -1},
};
int main() {
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> t[i];
		}
		int result = 0;
		for (int i = 0; i < 4; i++) {
			int res[256][256];
			memset(res, 0, sizeof(res));
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					int preX = k + d[i][0];
					int preY = j + d[i][1];
					if ((preX < 0 || preY < 0 || preX >= n) && t[j][k] == '1') {
						res[j][k] = 1;
					}
					else {
						if (t[j][k] == '1') {
							res[j][k] = res[preY][preX] + 1;
						}
					}
					result = max(result, res[j][k]);
					//cout << ' ' << res[j][k];
				}
				//cout << endl;
			}
		}
		cout << result << endl;
	}
}