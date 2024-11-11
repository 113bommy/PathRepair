#include <bits/stdc++.h>

int main()
{
	int N, M, P;
	scanf("%d%d%d", &N, &M, &P);
	using vpi = std::vector<std::pair<int, int>>;
	using vvpi = std::vector<vpi>;

	vvpi edges(N);
	for (int i{}; i < M; i++)
	{
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		A--; B--;
		edges[A].push_back({B, C - P});
	}
	std::vector<int64_t> distance(N, -(1ll << 60));
	distance[0] = 0;
	for (int loop{}; loop < N; loop++)
		for (int from{}; from < N; from++)
			for (auto& e: edges[from])
				distance[e.first] = std::max(distance[e.first], distance[from] + e.second);
	
	int64_t ans{distance.back()};
	for (int loop{}; loop < N; loop++)
		for (int from{}; from < N; from++)
			for (auto& e: edges[from])
				distance[e.first] = std::max(distance[e.first], distance[from] + e.second);
	
	if (ans != distance.back()) puts("-1");
	else printf("%lld\n", std::max(0l, ans));

	return 0;
}