#include<cstdio>

int d[3][1002][1002], N, M, K;

int main()
{
        char buf[1024];

        scanf("%d%d%d", &N, &M, &K);

        for (int i = 1; i <= N; i++) {
                scanf("%s", buf + 1);
                for (int j = 1; j <= M; j++)  {
                        for (int k = 0; k < 3; k++) {
                                d[k][i][j] = d[k][i][j-1] + d[k][i-1][j] - d[k][i-1][j-1];
                        }
                        switch (buf[j]) {
                                case 'J': d[0][i][j]++;break;
                                case 'O': d[1][i][j]++;break;
                                case 'I': d[2][i][j]++;
                        }
                }
        }

        while (K--) {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
                for (int i = 0; i < 3; i++) {
                        i?putchar(' ');printf("%d", d[i][y2][x2] - d[i][y1-1][x2] - d[i][y2][x1-1] + d[i][y1-1][x1-1]);
                }
                puts("");
        }

        return 0;
}