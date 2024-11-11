#include <stdio.h>
#include <algorithm>
#include <functional>

int N, A, B, C, D[112];
int ans = -1;

int main(void) {
	scanf("%d%d%d%d", &N, &A, &B, &C);
	for (int i = 0; i < N; ++i) { scanf("%d", &D[i]); }

	std::sort(D, D + N, std::greater<int>());
	int greatest_cal = C;
	int greatest_dollar = 0;
	for (int i = 0; i < N; ++i) {
		greatest_cal += D[i];
		greatest_dollar = A + B*(i + 1);
		ans = std::max(ans, greatest_cal / greatest_dollar);
	}

	printf("%d\n", ans);
	return 0;
}