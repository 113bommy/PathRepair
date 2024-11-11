n, m = map(int, input().split())
for i in range(m//n, 0, -1):
    if not m%i:
        print(i)
        break