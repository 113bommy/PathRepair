def byfirst(a):
    return a[0]

n = int(input())
x1, x2 = [int(i) for i in input().split()]
a = {}
for i in range(n):
    k, b = [int(i) for i in input().split()]
    x, y = k * x1 + b, k * x2 + b
    if x in a:
        a[x] += [y]
    else:
        a[x] = [y]
b = list(a.keys())
b.sort()
m = max(a[b[0]])
flag = 0
for i in b[1:]:
    if m > min(a[i]):
        flag = 1
        break
    else:
        m = max(a[i])
if flag:
    print("YES")
else:
    print("NO")


    
