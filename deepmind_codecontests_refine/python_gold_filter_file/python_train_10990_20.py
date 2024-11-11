a, b =map(int,input().split())
l = [31,28,31,30,31,30,31,31,30,31,30,31]
t = a-1
k = 1
for i in range(l[t]):
    if b > 7:
        b = 1
        k += 1
    b += 1
print(k)