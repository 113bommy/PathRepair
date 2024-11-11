#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

#define PLANE (-1)
#define HOUSE (1)
#define CHURCH (100)

using namespace std;

int x, y;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int home[10][10];
int n;
map<int, int> memo[24];

int goChurch(int ty, int tx)
{
    int i;
    int my, mx;
    for (i = 0; i < 4; i++){
        my = ty + dy[i];
        mx = tx + dx[i];
        while (0 <= my && my < y && 0 <= mx && mx < x){
            if (home[my][mx] == CHURCH){
                return (1);
            }
            my += dy[i];
            mx += dx[i];
        }
    }
    return (0);
}

int dfs(int v, int bit, int ty, int tx, char state[][11])
{
    int i;
    int ky, kx;
    int ans;
    
    if (memo[pos].find(bit) != memo[v].end()){
        return (memo[v][bit]);
    }
    
    if (bit == (1 << n) - 1){
        if (__builtin_popcount(bit) < 19){
            return (memo[v][bit] = goChurch(ty, tx));
        }
        return (goChurch(ty, tx));
    }
    
    ans = 0;
    
    for (i = 0; i < 4; i++){
		kx = tx + dx[i];
        ky = ty + dy[i];
        //ツ逆ツ渉づ可プツδ個ゼツδ督トツづーツ置ツつ「ツづつ「ツつュ
		while (0 <= kx && kx < x && 0 <= ky && ky < y && (home[ky][kx] == PLANE || home[ky][kx] == CHURCH || state[ky][kx] == 1)){
			ky += dy[i];
            kx += dx[i];
		}
		if (0 <= kx && kx < x && 0 <= ky && ky < y){
			state[ky][kx] = 1;
			ans += dfs(home[ky][kx] , bit | (1 << home[ky][kx]) , ky, kx, state);
			state[ky][kx] = 0;
		}
	}
    
    if (__builtin_popcount(bit) < 19){
        memo[v][bit] = ans;
    }
	return (ans);
}


int main(void)
{
    int sy, sx;
    int i, j;
    char state[10][11];
    
    while (1){
        scanf("%d%d", &x, &y);
        
        if (x + y == 0){
            break;
        }
        n = 0;
        for (i = 0; i < y; i++){
            for (j = 0; j < x; j++){
                scanf("%d", &home[i][j]);
                if (home[i][j] == 2){
                    home[i][j] = CHURCH;
                    sy = i;
                    sx = j;
                }
                else if (home[i][j] == HOUSE){
                    home[i][j] = n++;
                }
                else if (home[i][j] == 0){
                    home[i][j] = PLANE;
                }
            }
        }
        memset(state, 0, sizeof(state));
        for (i = 0; i < 24; i++){
            memo[i].clear();
        }
        printf("%d\n", dfs(n, 0, sy, sx, state));
    }
    
    return (0);
}