#include<bits.stdc++.h>
using namespace std;
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	printf("%d %d\n", min(a, b), max(0, a + b - n));
	return 0;
}