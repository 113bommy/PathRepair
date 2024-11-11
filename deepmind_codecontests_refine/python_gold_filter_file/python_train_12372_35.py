N = int(input())
A = [[] for i in range(N)]
for i in range(N):
    a = list(map(int, input().split()))
    A[i] = a


num = 0

for i in range(N):
    for j in range(i + 1, N):
        flag = True
        for k in range(N):
            if i == k or k == j:
                continue
            if A[i][j] > A[i][k] + A[k][j]:
                print(-1)
                exit()
            elif A[i][j] == A[i][k] + A[k][j]:
                flag = False

        if flag:
            num += A[i][j]

print(num)