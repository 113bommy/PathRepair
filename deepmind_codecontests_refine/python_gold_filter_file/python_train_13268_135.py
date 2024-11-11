n = int(input())
a = 0
for i in range(n):
    p, q = map(int,input().split())
    if q - p >= 2:
        a += 1
print(a)
