N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [input() for _ in range(M)]
for i in range(M):
    for j in range(N-M+1):
        str_n = ''.join(A[i][j:j+M])
        if str_n == B[i]:
            break
    else:
        print("No")
        exit()
else:
    print("Yes")