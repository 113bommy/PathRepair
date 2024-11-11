a, k = map(int, input().split())

for i in range(k):
    if (a % 10) == 0:
        a //= 10
    else:
        a -= 1

print(a)
