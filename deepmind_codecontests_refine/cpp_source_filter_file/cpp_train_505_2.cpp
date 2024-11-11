#include <cstdio>
#include <algorithm>

//#define scanf scanf_s

const int kMaxSquare = 64;
const int kMaxMoney = 5100;
const int kMaxGainMoney = 100;

int roulette[4];

typedef struct{
	int type;
	int value;
} BoardState;

BoardState board[kMaxSquare];

int bp(int X, int Y){
	float bp[kMaxSquare][kMaxMoney];
	float prob = 1.0f / static_cast<float>(X);

  for(int n = 0; n <= X; n++)
    for(int m = 0; m <= Y*kMaxGainMOney; m++)
      pb[n][m] = 0.0f;

	bp[0][0] = 1.0f;
	for (int n = 0; n < Y; n++){
    for (int m = 0; m <= kMaxGainMoney * n; m++){
      if(bp[n][m] == 0.0f) continue;
			for (int k = 0; k < X; k++){
        int pos = std::min(n+roulette[k], Y);
				if (board[pos].type == 1)
          bp[std::min(pos + board[pos].value, Y)][m] += bp[n][m] * prob;
				else if (board[pos].type == 2)
					bp[pos][m + board[pos].value] += bp[n][m]* prob;
				else if (board[pos].type == 3)
          bp[pos][std::max(m - board[pos].value, 0)] += bp[n][m] * prob;
				else
					bp[pos][m] += bp[n][m] * prob;
			}
		}
	}

	float res = 0.0f;
  for (int m = 0; m <= Y * kMaxGainMoney; m++)
		res += static_cast<float>(m) * bp[Y][m];
	return static_cast<int>(res);
}

int main(){
	while (1){
		int X, Y, Z;
		scanf("%d %d %d", &X, &Y, &Z);
		if (X == 0) return 0;
		for (int i = 0; i < X; i++)
			scanf("%d", &roulette[i]);
		for (int i = 0; i < kMaxSquare; i++)
			board[i] = { 0, 0 };
		for (; Z > 0; Z--){
			int N, E, A;
			scanf("%d %d %d", &N, &E, &A);
			board[N] = { E, A };
		}
		printf("%d\n", bp(X, Y));
	}
}