n = int(input())
ans = set()
f = lambda x: sum(int(i) for i in str(x))
for i in range(max(0, n - 1000), n + 1):
    if i + f(i) == n: ans.add(i)
print(len(ans))
for i in sorted(ans): print(i)