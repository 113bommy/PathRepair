def nod(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a

n = int(input())
a = [int(_) for _ in input().split()]
b = sorted(a, reverse = True)
m = b[0]
d = m - b[1]
for i in range(2, n):
    d = nod(d, m - b[i])
count = 0
for x in a:
    if x != m:
        count += (m - x)//d
print(count, d)
    



