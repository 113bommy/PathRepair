n=int(input())
a=list(map(int,input().split()))
b=[2]*n
for i in range(n,0,-1):
    if n//i==1:b[i-1]=a[i-1]
    else: b[i-1]=(sum(b[2*i-1::i])%2)^a[i-1]
print(sum(b))
for i in range(n):
    if b[i]==1:print(i+1,end=' ')