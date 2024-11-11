N,K=map(int,input().split())
A=list(map(int,input().split()))
a=A[:]
for _ in range(K):
    t=[0]*(N+1)
    for i in range(N):
        ti=a[i]
        t[max(0,i-ti)]+=1
        t[min(N,i+ti+1)]-=1
    a=[]
    for i in range(N):
        a.append(t[i])
        if i>0:
            a[i]+=a[i-1]
    if min(a)==N:
        break
print(*a)