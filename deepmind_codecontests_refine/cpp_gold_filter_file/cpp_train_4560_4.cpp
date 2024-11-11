#include <bits/stdc++.h>

int N;
int64_t K;
std::vector<int64_t> A, F;

bool able(int64_t);

int main()
{
	scanf("%d%lld", &N, &K);
	A.resize(N);
	F.resize(N);
	for (auto& e: A) scanf("%lld", &e);
	for (auto& e: F) scanf("%lld", &e);
	std::sort(A.rbegin(), A.rend());
	std::sort(F.begin(), F.end());
	int64_t ng{-1}, ok{1ll << 60};
	while (ok - ng > 1)
	{
		int64_t mid{(ok + ng) >> 1};
		if (able(mid)) ok = mid;
		else ng = mid;
	}
	printf("%lld\n", ok);

	return 0;
}

bool able(int64_t score)
{
	int64_t cost{};
	for (int i{}; i < N; i++)
		cost += std::max(0l, A[i] - score / F[i]);
	return cost <= K;
}