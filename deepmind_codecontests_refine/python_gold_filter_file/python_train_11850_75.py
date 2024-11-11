N,M = map(int, input().split())

if M%N == 0:
    ans = M//N
else:
    for i in range(M//N, 0, -1):
        ama = M - i*N
        if ama%i==0:
            ans = i
            break

print(ans)