a, n = map(int, input().split())
for i in range(n):
    if a % 10 != 0:
        a -= 1
    else:
        a //= 10
print(a)
