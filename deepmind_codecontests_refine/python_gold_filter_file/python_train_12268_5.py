from collections import Counter

n = int(input())
dl = list(map(int, input().split()))
m = int(input())
tl = list(map(int, input().split()))

dc = Counter(dl)
tc = Counter(tl)

for k in tc:
    if dc[k]<tc[k]:
        print("NO")
        exit()
print("YES")