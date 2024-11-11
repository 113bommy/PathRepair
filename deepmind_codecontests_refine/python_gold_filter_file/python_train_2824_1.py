input()
a = [int(x) for x in input().split(' ')]

m = 1
current = 1
for i in range(1,len(a)):
    if a[i-1] == a[i]:
        m = max(m, current)
        current = 0
    current += 1
if current > 0:
        m = max(m, current)

print(m)