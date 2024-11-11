n, v = map(int, input().split())
res = []
for i in range(1, n+1):
    li = list(map(int, input().split()))
    if min(li[1:])<v:
        res.append(i)
res.sort()
if len(res)==0:
    print(0)
else:
    print(len(res))
    print(" ".join(map(str, res)))