#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 10;

int a[N][N], h[N][N], n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    int cost = h[x][y] + a[x][y];
    for (int k = 0; k < 4; k++) {
        int tx = x + dx[k], ty = y + dy[k];
        if (h[tx][ty] > cost) {
            h[tx][ty] = cost;
            dfs(tx, ty);
        }
    }
}

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n;; j++) {
            h[i][j] = min(min(i - 1, n - i), min(j - 1, n - j));
            a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n * n; i++) {
        int pos;  scanf("%d", &pos);
        int row = (pos - 1) / n + 1, col = (pos - 1) % n + 1;
        ans += h[row][col];
        a[row][col] = 0;
        dfs(row, col);
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}