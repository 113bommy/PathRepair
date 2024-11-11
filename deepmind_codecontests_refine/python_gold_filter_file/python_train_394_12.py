N, x = map(int, input().split())
A = list(map(int, input().split()))

A.sort()
c = 0
for i in A:
    x -= i
    if x >= 0:
        c += 1
    else:
        break

if x > 0:
    c -= 1

print(c)
