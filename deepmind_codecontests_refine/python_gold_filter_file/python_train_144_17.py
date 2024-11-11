[n,c] = input().split()
maxof=0
c=int(c)
g=input().split()
for i in range(1,int(n)):
    h=int(g[i-1])
    k=int(g[i])
    if maxof<(h-k-c):
        maxof=h-k-c
print(maxof)
