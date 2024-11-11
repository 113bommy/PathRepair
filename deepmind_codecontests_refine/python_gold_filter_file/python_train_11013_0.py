n,k,q=map(int,input().split())
res=[q-k]*n
a=[int(input())-1 for _ in range(q)]

for e in a:
    res[e]-=1

for e in res:
    print('Yes' if e<0 else 'No')