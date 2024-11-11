#include <bits/stdc++.h>

using namespace std;

int memo[3123][3123],N,T;

vector <pair <int,int> > vet;

int Ray(int pos, int tempo){
	if (pos == N)
		return 0;
	if (tempo >= T)
		return 0;
	if (memo[pos][tempo] != -1)
		return memo[pos][tempo];

	return memo[pos][tempo]=max(Ray(pos+1,tempo),Ray(pos+1,tempo+vet[pos].first)+vet[pos].second);
}
int main() {
	int aux1,aux2;
	scanf("%d%d", &N, &T);
	memset(memo, -1, sizeof(memo));
	for (int i = 0;i < N;i++) {
		scanf("%d%d", &aux1,&aux2);
		vet.push_back(make_pair(aux1,aux2));
	}
  sort(vet.begin(), vet.end());

	printf("%d\n",Ray(0,0));

	return 0;
}
