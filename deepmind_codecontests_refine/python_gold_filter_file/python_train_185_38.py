def prime_decomposition(n):
    i = 2
    table=[]
    while i*i<=n:
        count=0
        while n%i==0:
            n/= i
            count+=1
        table.append([int(i),count])
        i += 1
    if n > 1:
        table.append([int(n),1])
    return table
N,P=map(int,input().split())
ans=1
for A in prime_decomposition(P):
    if A[1]>=N:
        ans*=A[0]**int(A[1]/N)
print(ans)