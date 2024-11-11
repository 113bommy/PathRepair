a = [int(x) for x in input().split()]
n = a[0]
m = a[1]

a = []
b = []
c = []
for i in range(n):
    d = [int(x) for x in input().split()]
    a.append(d[0])
    b.append(d[1])
    c.append(d[0]-d[1])

c.sort(reverse=True)


w  = sum(a) - m

i=0
while (w > 0 and i<n):
    w-=c[i]
    i+=1
if (i==n and w>0):
    print (-1)
else:
    print(i)





