#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

template<class T> inline void chmax(T& a, const T& b) { if(b > a) a = b; }

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<double> l(n), a(n), b(n);
	for(int i = 0; i < n; ++i)
		scanf("%lf %lf %lf", &l[i], &a[i], &b[i]);

	vector<vector<double> > dist(n, vector<double>(n));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			const double dl = l[i] - l[j], da = a[i] - a[j], db = b[i] - b[j];
			dist[i][j] = dl * dl + da * da + db * db;
		}
	}

	double ans = 0.0;
	for(int i = 0; i < (1 << n); ++i) {
		if(__builtin_popcount(i) != m)
			continue;

		double tmp = 0.0;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j)) {
				for(int k = j + 1; k < n; ++k)
					if(i & (1 << k))
						tmp += dist[j][k];


		chmax(ans, tmp);
	}

	printf("%.20lf\n", ans);

	return EXIT_SUCCESS;
}