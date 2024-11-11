n,k=map(int,input().split())
l=list(map(int,input().split()))
for i in range(k,n):
    if l[i-k]<l[i]:
        print('Yes')
    else:
        print('No')