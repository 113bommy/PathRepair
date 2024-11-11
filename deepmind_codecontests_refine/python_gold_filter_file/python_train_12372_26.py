N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
INF = float('inf')

for i in range(N):
    A[i][i] = INF

answer = 0
for i in range(N):
    for j in range(i+1, N):
  
        count = INF
        for k in range(N):   
            count = min(count, A[i][k] + A[k][j])
        
        if A[i][j] > count:
            print(-1)
            exit()

        if A[i][j] < count:
            answer += A[i][j]
        
print(answer)