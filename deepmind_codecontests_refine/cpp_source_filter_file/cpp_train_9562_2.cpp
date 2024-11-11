#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, t, ans = 0, i = 1, a, b;
	cin >> num >> t >> b;
	for (; i < num; i++) {
		scanf_s("%d", &a);
		ans += min(t, a - b);
		b = a;
	}
	cout << ans + t << "\n";
	return 0;
}
