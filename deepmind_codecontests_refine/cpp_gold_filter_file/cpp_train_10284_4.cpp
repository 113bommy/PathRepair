#include <bits/stdc++.h>
using namespace std;

int K, A, B;
int main()
{
	scanf("%d%d%d", &K, &A, &B);
	printf((A - 1) / K != B / K ? "OK" : "NG");
	return 0;
}