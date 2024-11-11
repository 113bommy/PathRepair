#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d",max(max(2*a-1,2*b-1),a+b));
}