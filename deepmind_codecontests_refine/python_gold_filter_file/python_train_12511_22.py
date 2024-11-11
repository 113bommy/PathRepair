n, k = map(int, input().split())
r = min(n, int(1e6))
for i in range(1, r+1):
    sm = i*(i+1)//2
    y = sm-k
    if y >= 0 and y+i == n:
        print(y)
        break
