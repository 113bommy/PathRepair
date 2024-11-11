n,q = map(int,input().split())
rl = [0] * n
al = [0] * n
for i in range(n-1):
    a,b = map(int,input().split())
    rl[b-1] = a -1
for j in range(q):
    p,x = map(int,input().split())
    al[p-1] += x
for k in range(1,n):
    al[k] += al[rl[k]]
print(*al)
