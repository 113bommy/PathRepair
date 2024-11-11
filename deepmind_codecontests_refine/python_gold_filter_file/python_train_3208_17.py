N=int(input())
P=N if N%2 else N+1
print(N*(N-1)//2-N//2)
for i in range(1,N+1):
    for j in range(1,i):
        if i+j==P:
            continue
        print(i,j)