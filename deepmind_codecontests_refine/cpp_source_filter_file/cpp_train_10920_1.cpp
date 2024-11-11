#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int x, int y, int w, int h, vector<vector<int> > f)
{
int ans = 0;

if(f[x][y] == 0)
return 0;

f[x][y] = 0;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

for(int i = 0; i < 4; ++i) {
int nx = dx[i] + x;
int ny = dy[i] + y;
if(nx < 0 || ny < 0 || nx >= w || ny >= h)
continue;
int tmp = solve(nx, ny, w, h, f);
ans = max(ans, tmp);
}

f[x][y] = 1;

return ans + 1;
}

int main()
{
while(true) {
int w, h;
vector<vector<int> f;
scanf("%d%d", &w, &h);
if(w == 0)
break;
f.resize(w);
for(int i = 0; i < w; ++i)
f[i].resize(h);
for(int y = 0; y < h; ++y) {
for(int x = 0; x < w; ++x)
scanf("%d", &f[x][y]);
}
int ans = 0;
for(int x = 0; x < w; ++x) {
for(int y = 0; y < h; ++y)
ans = max(ans, solve(x, y, w, h, f));
}
printf("%d\n", ans);
}
return 0;
}