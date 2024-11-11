n, k = map(int, input().split())
j = 0
while k**j <= n:
    j += 1
print(j)