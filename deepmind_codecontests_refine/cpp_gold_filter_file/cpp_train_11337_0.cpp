#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;//JOI?????????????????°
	int m;//?????????????????°
	int person[101] = { 0 };//???????????????
	int baton[101] = { 0 };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> person[i];
	}
	//cout << "ruio";
	for (int k = 1; k <= m; k++) {
		int i = 1;
		//cout << "ruio";
		while (i != n) {
			if (1 <= i&&i <= n - 1) {
				if (person[i] % k > person[i + 1] % k) {
					//	cout << "ruio";
					swap(person[i], person[i + 1]);
					i = i + 1;
				}
				else {
					i = i + 1;
				}
			}
		}
	}
	for (int j = 1; j <= n; j++) {
		cout << person[j] << endl;
	}
}