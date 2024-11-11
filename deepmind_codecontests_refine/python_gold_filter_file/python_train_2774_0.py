N, K = map(int, input().split())
a = list(map(int, input().split()))

m, type, num = N + 1, -1, -1

for i, el in enumerate(a, 1):
    temp = N % el
    if temp < m:
        m = temp
        type = i
        num = N // el

print(type, num)
