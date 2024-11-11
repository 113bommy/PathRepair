n = int(input())
s = list(map(int, input().split()))

s.sort()

res = []
left = []

for i in range(len(s)-1, -1, -1):
    if i % 2 == 0:
        res.append(s[i])
    else:
        left.append(s[i])

left.reverse()
res.extend(left)

ok = True

for i in range(len(res)):
    pred = i - 1
    if pred == -1:
        pred = len(res)-1
    succ = i + 1
    if succ == len(res):
        succ = 0
    if res[succ] + res[pred] <= res[i]:
        ok = False
        break

if not ok:
    print("NO")
else:
    print("YES")
    print(" ".join(str(x) for x in res))