N = int(input())
S = [input() for i in range(N)]

def check(A, B):
    for i in range(N):
        for j in range(i+1, N):
            if S[(A+i)%N][(B+j)%N] != S[(A+j)%N][(B+i)%N]:
                return 0
    return 1

ans = 0
for i in range(N):
    ans += N*check(0, i)
print(ans)
