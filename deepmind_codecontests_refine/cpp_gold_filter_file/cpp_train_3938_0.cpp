#include<bits/stdc++.h>
using namespace std;
char s[100010];
int n, x = 1;
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if (s[1] == '0' || s[n] == '1')
		return printf("-1\n"), 0;
	for (int i = 1; i < n; i ++)
		if (s[i] ^ s[n - i]) 
			return printf("-1\n"), 0;
	for (int i = 2; i <= n; i ++) {
		printf("%d %d\n", x, i);
		if (s[i - 1] == '1')
			x = i;
	}
	return 0;
}