n,k=map(int,input().split())
a=[int(i) for i in input().split()]
k=min(k,41)

for j in range(k):
    b=[0 for i in range(n)]
    for i in range(n):
        l=max(0,i-a[i])
        r=min(n-1,i+a[i])
        b[l]+=1
        if r+1<n:
            b[r+1]-=1
    for i in range(1,n):
      b[i]+=b[i-1]
    a=b
print(" ".join(map(str,a)))