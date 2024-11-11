n, m = input().split()
c=0
m,n=int(m),int(n)
for i in range(n):
    a = list(map(int,input().split()))
    for i in range(m):
        if a[2*i] or a[2*i+1] : c+=1
print(c)
