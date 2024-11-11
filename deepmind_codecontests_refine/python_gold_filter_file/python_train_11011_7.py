def Csum(a):
    b,c=[0],0
    for i in range(len(a)):
        c+=a[i]
        b.append(c)
    return b

n,k=map(int,input().split())
a=list(map(int,input().split()))
if k>100:
    a=[n]*n
    print(*a)
    exit()
for i in range(k):
    b=[0]*(n+1)
    for j in range(n):
        l,r=max(0,j-a[j]),min(n,j+a[j]+1)
        b[l]+=1
        b[r]-=1
    a=Csum(b)[1:-1]
print(*a)