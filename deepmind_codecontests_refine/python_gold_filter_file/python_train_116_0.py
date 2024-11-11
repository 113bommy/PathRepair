N = int(input())
S = input()

prev = set()
ans = []
f = False
for s in S:

    for p in prev:
        if s < p:
            ans.append((p, s))
            f = True
    if f:
        break
    prev.add(s)

if len(ans) == 0:
    print("NO")
else:
    print("YES")
    a = S.index(ans[0][0])
    tmp = list(S)
    tmp = tmp[::-1]
    b = tmp.index(ans[0][1])
    print(a + 1, N - b)
