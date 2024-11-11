n = int(input())
a = input()
a = [int(x) for x in a.split()]
f = 1
a.sort()
b=[]
c=[]
a.sort()
for i in range(n):
    b.append(a[i])
    c.append(a[i+n])
for i in range(n):
    for j in range(n):
        if b[i]==c[j]:
            f=0
            break
if f:
    print("YES")
else:
    print("NO")