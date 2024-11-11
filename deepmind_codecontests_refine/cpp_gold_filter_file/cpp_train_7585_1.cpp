#include<iostream>
using namespace std;
int map[110];
bool solve() {
	if (map[1] % 2 == 1 && map[2] % 2 == 1) {
		for (int i = 3; i <= 100; i++){
			if (map[i] % 2 == 1)
				return false;
		}
		return true;
	}
	else return false;
}
int main() {
	int a, b;
	while (cin >> a >> b) {
		if (!a && !b) {
			if (solve()) cout << "OK\n";
			else cout << "NG\n";
			for (int i = 1; i <= 100; i++)map[i] = 0;
			continue;
		}
		else {
			map[a]++;
			map[b]++;
		}
	}
}