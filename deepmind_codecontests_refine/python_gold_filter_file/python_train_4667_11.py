H,W = map(int, input().split())
a = [list(input()) for i in range(H)]
a = [x for x in a if '#' in x]

aT = list(zip(*a))
aT = [x for x in aT if '#' in x]
ans = list(zip(*aT))

for i in ans:
    print("".join(i))
