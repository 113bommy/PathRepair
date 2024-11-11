n,k=map(int,input().split())
d=list(map(int,input().split()))

ds = []

for i in range(0,n):
    sum = 0
    for j in range(i,n):
        sum += d[j]
        ds.append(sum)
        #print(str(sum) + " ",end='')
    #print()

ds.sort(reverse=True)

sum = 0
for i in range(40,-1,-1):
    count = 0
    o = []
    for dss in ds:
        if dss & (1 << i) > 0 :
            count += 1
            o.append(dss)

    if count >= k :
        sum += 1 << i
        ds = o

print(sum)