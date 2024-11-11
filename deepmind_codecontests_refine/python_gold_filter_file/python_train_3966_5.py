n, m = list(map(int, input().split()))
pairs = []
for i in range(m):
    l, r = list(map(int, input().split()))
    pairs.append((l, r))
r = True
for i in range(n):
    print("1" if r else "0", end='')
    r = not r
