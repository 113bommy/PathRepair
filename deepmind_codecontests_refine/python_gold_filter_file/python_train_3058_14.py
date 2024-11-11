a, b, n = list(map(int, input().split()))

p = None
for i in range(10):
    k = a * 10 + i
    if k % b == 0:
        p = i
        break

if p!=None:
    print(("{}{}" + "0"*(n-1)).format(a, p))
else:
    print(-1)
