q = int(input())
for step in range(q):
    l, r = map(int, input().split())
    if l % 2 == 1:
        print((r - l + 1)//2 - r*(r%2))
    else:
        print(-((r - l + 1)//2) + r*(1 - r%2))