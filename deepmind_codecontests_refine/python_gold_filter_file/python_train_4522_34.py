a = list(input())
b = list(input())


x = "D" if a[1] > b[1] else 'U'
y = "L" if a[0] > b[0] else 'R'


m = abs(ord(a[0]) - ord(b[0]))
n = abs(ord(a[1]) - ord(b[1]))


c = max(m , n)
print(c)
j = y+x

for _ in range(min(m,n)):
    print(j)
mini = min(m,n)

m -= mini
n -= mini


for _ in range(m): print(y)
for _ in range(n): print(x)
