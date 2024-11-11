n, m = map(int, input().split())

st = m//n

for i in range(st, 0, -1):
    mod = m - n*i
    if mod % i == 0:
        print(i)
        break