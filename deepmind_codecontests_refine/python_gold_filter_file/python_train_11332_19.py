N,M=map(int, input().split())
A=[input() for _ in range(N)]
B=[input() for _ in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        t=[k[j:j+M] for k in A[i:i+M]]
        if t==B:
            print('Yes')
            exit()
print('No')
