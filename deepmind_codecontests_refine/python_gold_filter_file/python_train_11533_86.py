from collections import deque
H, W= map(int, input().split())
CH, CW= map(int, input().split())
DH, DW= map(int, input().split())
S = [list(map(str, input())) for _ in range(H)]
q = deque([(CH-1, CW-1, 0)])
while q:
    h, w, c = q.popleft()
    if S[h][w] == '.':
        S[h][w] = c
        for i in range(-2, 3):
            for j in range(-2, 3):
                if 0<=h+i<H and 0<=w+j<W and S[h+i][w+j] == '.':
                    if abs(i)+abs(j) == 1:
                        q.appendleft((h+i, w+j, c))
                    elif abs(i)+abs(j) >= 2:
                        q.append((h+i, w+j, c+1))
if S[DH-1][DW-1] == '.':
    print(-1)
else:
    print(S[DH-1][DW-1])