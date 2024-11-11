#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

vector<pair<long long int, long long int>>ps;
long long int g(long long int x, long long int place) {
	return ps[x].first + ps[x].second*(place);
}

int main() {
	long long int N, L, K; cin >> N >> L >> K;
	vector<long long int>sums(N + 1);
	for (int i = 0; i < N; ++i) {
		int a, d; cin >> a >> d;
		ps.emplace_back(a, d);

		sums[i + 1] = sums[i] + (a + (a + d*(L - 1)))*L / 2;
	}

	long long int answer = 0;
	if (N == 1) {
		answer = (g(0, L - K) + g(0, L - 1))*K / 2;

	}
	else if (N*L == K) {
		answer = sums[N];
	}
	else {

		const long long int t = K / L;

		for (long long int len = t - 1; len <= t; ++len) {
			for (int l = 1; l + len < N; ++l) {
				int r = l + len;

				long long int rest = K - L*len;

				if (rest <= L) {

					long long int now_ans = sums[r] - sums[l] +
						(g(l - 1, L - rest) + g(l - 1, L - 1))*
						rest / 2;

					long long int r_minus_l_start = g(r, 0) - g(l - 1, L - rest);
					long long int r_minus_l_sa = ps[r].second - ps[l - 1].second;

					long long int max_cnt;
					if (r_minus_l_sa > 0) {
						max_cnt = rest;
					}
					else if (r_minus_l_sa == 0) {
						if (r_minus_l_start > 0) {
							max_cnt = rest;
						}
						else {
							max_cnt = 0;
						}
					}
					else {
						if (r_minus_l_start > 0) {
							long long int k = r_minus_l_start / (-r_minus_l_sa) + 1;
							max_cnt = min(rest, k);
						}
						else {
							max_cnt = 0;
						}
					}

					long long int max_ans = now_ans + r_minus_l_start*max_cnt +
						r_minus_l_sa*(max_cnt - 1)*max_cnt / 2;

					answer = max(answer, now_ans);
					answer = max(answer, max_ans);
					answer = max(answer,
						now_ans + r_minus_l_start*rest +
						r_minus_l_sa*(rest - 1)*rest / 2);

				}
				else {

					long long int now_ans = sums[r] - sums[l - 1]
						+ (ps[r].first + (ps[r].first + ps[r].second*(rest - L - 1)))*(rest - L) / 2);

					long long int r_minus_l_start = g(r, rest - L) - g(l - 1, 0);
					long long int r_minus_l_sa = ps[r].second - ps[l - 1].second;

					long long int max_cnt;
					if (r_minus_l_sa > 0) {
						max_cnt = 2 * L - rest;
					}
					else if (r_minus_l_sa == 0) {
						if (r_minus_l_start > 0) {
							max_cnt = 2 * L - rest;
						}
						else {
							max_cnt = 0;
						}
					}
					else {
						if (r_minus_l_start > 0) {
							long long int k = r_minus_l_start / (-r_minus_l_sa) + 1;
							max_cnt = min(2 * L - rest, k);
						}
						else {
							max_cnt = 0;
						}
					} 
					long long int a=now_ans;
					long long int b=r_minus_l_start*max_cnt;
					long long int c=r_minus_l_sa*(max_cnt-1ll)*max_cnt/2ll;
					long long int abc=a+b+c;
					long long int max_ans = now_ans + r_minus_l_start*max_cnt +
						(r_minus_l_sa*(max_cnt - 1)*max_cnt) / 2ll;

					long long int kk=(g(l-1,max_cnt)+g(l-1,L-1))*(L-max_cnt)/2+
						sums[r] - sums[l]+
						(g(r,0)+g(r,rest-L-1+max_cnt))*(rest-L+max_cnt)/2;
					{
						long long int fx=0;
					swap(fx,max_cnt);
					long long int akk = (g(l - 1, max_cnt) + g(l - 1, L - 1))*(L - max_cnt) / 2 +
						sums[r] - sums[l] +
						(g(r, 0) + g(r, rest - L - 1 + max_cnt))*(rest - L + max_cnt) / 2;
					swap(fx,max_cnt);
					}
					max_cnt++;
					auto max2 = now_ans + r_minus_l_start*max_cnt +
						r_minus_l_sa*(max_cnt - 1)*max_cnt / 2;
					max_cnt -= 2; 
					auto max3 = now_ans + r_minus_l_start*max_cnt +
						r_minus_l_sa*(max_cnt - 1)*max_cnt / 2;
					max_cnt++;
					answer = max(answer, now_ans);
					answer = max(answer, max_ans);
					//answer=max(answer,max2);
					//answer=max(answer,max3);
					answer = max(answer,
						now_ans + r_minus_l_start*(2 * L - rest) +
						r_minus_l_sa*((2 * L - rest) - 1)*(2 * L - rest) / 2);

					if (answer == 2707366438153060
						) {
						//cout<<answer<<endl;
					}
				}
			}
		}
	}


	cout << answer << endl;
	return 0;
}
