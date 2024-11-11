ro = 0
lc = 0
lo = 0
rc = 0
r = []
l = []
n = int(input())
for i in range(0,n):
    l = list(map(int,input().split()))
    if l[0] == 1:
        lo +=1
    else:
        lc+=1

    if l[1] == 1:
        ro+=1
    else:
        rc+=1
maxl = max(lo,lc)
maxr = max(ro,rc)
print((n-maxl)+(n-maxr))
