n = int(input())
a = [int(x) for x in input().split()]
x = a.index(1)
y = a.index(n)
hsl = max(abs(x-y), abs(n-1-x), abs(n-1-y), x, y)
print (hsl)
