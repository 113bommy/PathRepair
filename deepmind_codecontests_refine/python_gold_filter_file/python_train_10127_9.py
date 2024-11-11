def shares(A):
    n=len(A)
    if n==1:
        return A[0]
    sum=0
    cost=A[0]
    sell=A[0]
    for i in range(1,n):
        if A[i]>sell:
            sum+=cost-sell
            cost=A[i]
            sell=A[i]
        else:
            sell=min(sell,A[i])
    return sum+cost
t=int(input())
for i in range(t):
    n,q=input().split()
    n=int(n)
    A=[int(i) for i in input().split()][:n]
    print(shares(A))