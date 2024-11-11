n, t = map(int, input().split())
a = list(map(int, input().split()))

for i,j in enumerate(a):
    t=t-(86400-j)
    if t <= 0:
        print(i+1)
        break