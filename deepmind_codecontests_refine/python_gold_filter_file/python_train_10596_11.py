n, k = map(int, input().split())
p = 0
while n >= k ** p:
    p += 1
print(p)