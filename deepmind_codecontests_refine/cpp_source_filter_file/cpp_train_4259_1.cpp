 <cstdio>

using namespace std;

int card[256];

int main()
{
    int n;

    while (scanf("%d", &n), n){
        for (int i = 1; i < n * 2 + 1; i++){
            card[i] = 2;
        }

        for (int i = 0; i < n; i++){
            int pass;
            scanf("%d", &pass);

            card[pass] = 1;
        }

        int i = 0;
        int turn = 1;
        int now = 1;
        int hand[2] = {n, n};

        while (hand[0] && hand[1]){
            if (card[now] == turn){
                card[now] = 0;
                hand[turn - 1]--;
                turn = turn == 1 ? 2 : 1;
            }
            now++;

            if (now > n * 2 + 1){
                now = 1;
                turn = turn == 1 ? 2 : 1;
            }
        }

        printf("%d\n", hand[1]);
        printf("%d\n", hand[0]);
    }

    return (0);
}