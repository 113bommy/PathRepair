n = int(input())
tic = input()
a, b = list(tic[:n]), list(tic[n:])
a.sort()
b.sort()
if a[0] > b[0]:
    a, b = b, a
for i in range(n):
    if a[i] >= b[i]:
        print("NO")
        break
else:
    print("YES")
