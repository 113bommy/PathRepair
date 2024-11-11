#include <bit/stdc++.h>
using namespace std;
int n;

int main() {
	cin >> n;
	if(n / 10 == 9 || n % 10 == 9) puts("Yes");
	else puts("No");
}