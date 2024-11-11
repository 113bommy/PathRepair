k, l, m, n, d, a= int(input()), int(input()), int(input()), int(input()), int(input()), []
a = set(a)
for i in range(k-1,d,k):
    a.add(i)
for i in range(l-1,d,l):
    a.add(i)
for i in range(m-1,d,m):
    a.add(i)
for i in range(n-1,d,n):
    a.add(i)
print(len(a))