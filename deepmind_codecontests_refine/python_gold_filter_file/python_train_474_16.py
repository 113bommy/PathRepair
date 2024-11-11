n, k = [int(s) for s in input().split()]
w = [int(s) for s in input().split()]
d = 0
for i in range(n):
    if w[i]>=2*k:
        d+=w[i]//(2*k)
        w[i]=w[i]%(2*k)
for i in range(n):
    if w[i]>k:
        d+=1
        w[i]=0
m=0
for i in range(n):
    if w[i]>0:
        m+=1
d+=m//2+m%2
print(d)