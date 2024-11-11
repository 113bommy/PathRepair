n, m = [int(i) for i in input().split()]
mini = 0
flag = 0
dist = []
for i in range(n):
    l = list(input())
    S = l.index("S")
    G = l.index("G")
    if G>S:
        flag = 1
    else:
        dist.append(S-G)


if flag==1:
    print(-1)
else:
    print(len(set(dist)))


