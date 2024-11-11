x, y, z, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
e = []
for i in a:
    for j in b:
        e.append(i + j)
e = sorted(e, reverse=True)[:k]
ans = []
for i in e:
    for j in c:
        ans.append(i + j)
ans = sorted(ans, reverse=True)[:k]
for i in ans:
    print(i)