n, r = map(int, input().split())
for _ in range(r):
    if n%10 == 0:
        n = n//10
    else:
        n -= 1
print(n)