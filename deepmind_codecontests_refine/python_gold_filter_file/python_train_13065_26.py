n, m = [int(s) for s in input().split()]
c = 0
for i in range (n):
    a = [int(s) for s in input().split()]
    for j in range(m):
        if (a[2*j]+a[2*j+1]) != 0:
            c +=1
print(c)    