#include <bits/stdc++.h>
using namespace std;
const int N = 1234;
 
int col[N];
char s[N][N];
 
int main() 
{
	int h;
	scanf("%d", &h);
	int w = h;
	for (int i = 0; i < h; i++) 
		scanf("%s", s[i]);
	bool any = false;
	for (int i = 0; i < h; i++) 
		for (int j = 0; j < w; j++) 
			any |= (s[i][j] == '#');
	
	if (!any)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < h; i ++) 
		for (int j = 0; j < w; j ++)
			if (s[i][j] == '#') 
				col[j] ++;
 
	int ans = (int) 2 * h + 1;
	for (int i = 0; i < h; i ++) 
	{
		int cur = 0;
		if (col[i] == 0) cur ++;
		for (int j = 0; j < w; j ++)
			if (s[i][j] == '.')
				cur ++;
		for (int j = 0; j < w; j ++) 
			if (col[j] < h) 
				cur ++;
		ans = min(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}