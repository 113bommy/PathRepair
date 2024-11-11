#include <bits/stdc++.h>

int main()
{
	int N, M, P;
	scanf("%d%d%d", &N, &M, &P);
	using vpi = std::vector<std::pair<int, int64_t>>;
	using vi = std::vector<int>;
	std::vector<vpi> edges(N);
	std::vector<vi> rev_edges(N);
	for (int i{}; i < M; i++)
	{
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		A--; B--;
		edges[A].push_back({B, C - P});
		rev_edges[B].push_back(A);
	}
	std::vector<int64_t> distance(N, -(1ll << 60));
	distance[0] = 0;
	for (int loop{}; loop < N; loop++)
		for (int i{}; i < N; i++)
			if (distance[i] != -(1ll << 60))
				for (auto& e: edges[i])
					distance[e.first] = std::max(distance[e.first], distance[i] + e.second);
	std::vector<int64_t> check{distance};
	for (int loop{}; loop < N; loop++)
		for (int i{}; i < N; i++)
			if (distance[i] != -(1ll << 60))
				for (auto& e: edges[i])
					if (distance[e.first] < distance[i] + e.second)
						distance[e.first] = 1ll << 60;
	if (distance[N - 1] == (1ll << 60))
		puts("-1");
	else
		printf("%lld\n", std::max(0ll, distance[N - 1]));

	return 0;
}