#include <bits/stdc++.h>
using namespace std;
int main() {
	char a[110];
	scanf("%s", a + 1);
	int n = strlen(a + 1);
	int pp = 0;
	for(int i = 2; i <= n; i++)
		if(a[i] != '9') 
			pp = 1;
	cout << a[1] - '0' - pp + (n - 1) * 9;
	return 0;
}