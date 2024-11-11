_ = int(input())
a = list(map(int, input().split()))
b = set()
c = 0
for e in a:
    if e >= 3200:
        c += 1
    else:
        b.add(e // 400)
print(max(len(b), 1), len(b) + c)
