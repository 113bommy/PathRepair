n = int(input())
a = [int(i) for i in input().split()]
x = [0]*n
for i in range(n,0,-1):
    m,c = 2,0
    while i*m<=n:
        c+=x[i*m-1]
        m+=1
    x[i-1] = (a[i-1]+c%2)%2
print(sum(x))
for i in range(n):
    if x[i]: print(i+1)