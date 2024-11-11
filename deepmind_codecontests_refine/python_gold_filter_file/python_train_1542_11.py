n=int(input())
a=[0]+list(map(int,input().split()))
b=[0]*(n+1)
for i in reversed(range(1,n+1)):
    if sum(b[i::i])%2!=a[i]:
        b[i]=1
print(sum(b))
for i,j in enumerate(b):
    if j==1:
        print(i,end=' ')
