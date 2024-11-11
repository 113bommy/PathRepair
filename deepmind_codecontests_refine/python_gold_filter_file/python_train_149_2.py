n,m = list(map(int,input().split()))
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = set()
l = 0
d = []
for i in range(m):
    if b[i] in c:
        k = len(d)
        j = 0
        while j<k:
            if d[j]!=b[i]:
                l+=a[d[j]-1]
                j+=1
            else:
                break
        d = [b[i]]+d[0:j]+d[j+1:]
    else:
        for j in d:
            l+=a[j-1]
        d = [b[i]]+d
        c.add(b[i])
print(l)
