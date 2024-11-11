#include <iostream>
using namespace std;

int main() {
	int h, w; cin >> h >> w;
	char buf[105];

	for (int y = 0; y < h; y++) {
		scanf("%s", buf);
		printf("%s\n%s\n", buf, buf);
	}

	return 0;
}