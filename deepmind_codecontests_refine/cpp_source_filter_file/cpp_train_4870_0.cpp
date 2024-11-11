#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

using namespace std;

constexpr int mod = 1000000007;
constexpr int v[] = { 0, 765144583, 346175634, 347662323, 5655049, 184117322, 927321758, 444014759, 542573865, 237315285, 417297686, 471090892, 183023413, 660103155, 727008098, 539588932, 729548371, 700407153, 404391958, 962779130, 184117322, 927321758, 444014759, 542573865, 237315285, 417297686, 471090892, 183023413, 660103155, 727008098 };

int main() {
	int N, T; scanf_s("%d", &T);
	for (int _t = 0; _t < T; _t++) {
		scanf_s("%d", &N);
		int ans = 869418286;
		if (N & 1) {// odd
			for (int i = 14, j = 29; i >= 0; i--, j--) {
				ans = ((long long)ans * N + v[j]) % mod;
			}
		}
		else {// even
			for (int i = 14; i >= 0; i--) {
				ans = ((long long)ans * N + v[i]) % mod;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}