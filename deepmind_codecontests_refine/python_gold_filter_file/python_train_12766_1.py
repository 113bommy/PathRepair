n=int(input())

a=list(map(int,input().split()))
b=a.copy()
a.sort()
c=[]
for i in range(n):
    c.append(a[(a.index(b[i])+1)%n])
print(*c)


