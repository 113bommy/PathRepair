#include <bits/stdc++.h>
using namespace std;
int x,y,ans,Min;
int main() {
	scanf("%3d",&x);
	Min = abs(753-x);
	while (scanf("%1d",&y) != EOF) {
		x = (x*10+y)%1000;
		if (abs(753-x) < Min) Min = abs(753-x);
	}
	printf("%d",min(Min,753));
	return 0;
}