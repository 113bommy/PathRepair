#include <stdio.h>
#include <algorithm>
#include <tuple>
using namespace std;
int n, ret, res, ptr; tuple<int, int, int> d[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", &get<0>(d[i]), &get<1>(d[i]), &get<2>(d[i]));
	sort(d, d + n);
	for (int i = 0; i < n; i++) {
		res = get<2>(d[i]);
		ptr = lower_bound(d, d + n, make_tuple(get<0>(d[i]), get<1>(d[i]) + 2, 0)) - d - 1;
		if (get<0>(d[ptr]) == get<0>(d[i]) && get<1>(d[ptr]) == get<1>(d[i]) + 1) res += get<2>(d[ptr]);
		ptr = lower_bound(d, d + n, make_tuple(get<0>(d[i]) + 1, get<1>(d[i]) + 1, 0)) - d - 1;
		if (get<0>(d[ptr]) == get<0>(d[i]) + 1 && get<1>(d[ptr]) == get<1>(d[i])) res += get<2>(d[ptr]);
		ptr = lower_bound(d, d + n, make_tuple(get<0>(d[i]) + 1, get<1>(d[i]) + 2, 0)) - d - 1;
		if (get<0>(d[ptr]) == get<0>(d[i]) + 1 && get<1>(d[ptr]) == get<1>(d[i]) + 1) res += get<2>(d[ptr]);
		ret = max(res, ret);
		res = get<2>(d[i]);
		ptr = lower_bound(d, d + n, make_tuple(get<0>(d[i]), get<1>(d[i]), 0)) - d - 1;
		if (get<0>(d[ptr]) == get<0>(d[i]) && get<1>(d[ptr]) == get<1>(d[i]) - 1) res += get<2>(d[ptr]);
		ptr = lower_bound(d, d + n, make_tuple(get<0>(d[i]) + 1, get<1>(d[i]) + 1, 0)) - d - 1;
		if (get<0>(d[ptr]) == get<0>(d[i]) + 1 && get<1>(d[ptr]) == get<1>(d[i])) res += get<2>(d[ptr]);
		ptr = lower_bound(d, d + n, make_tuple(get<0>(d[i]) + 1, get<1>(d[i]), 0)) - d - 1;
		if (get<0>(d[ptr]) == get<0>(d[i]) + 1 && get<1>(d[ptr]) == get<1>(d[i]) - 1) res += get<2>(d[ptr]);
		ret = max(res, ret);
	}
	printf("%d / 1\n", ret);
	return 0;
}