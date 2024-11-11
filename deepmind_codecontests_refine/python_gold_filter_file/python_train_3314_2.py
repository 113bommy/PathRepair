import collections
n, k = map(int, input().split())
a = list(map(int, input().split()))
t = 0
ans = n

l = collections.Counter(a)
x = l.most_common(k)

for i in range(len(x)):
    t += x[i][1]

ans -= t
if ans < 0:
    ans = 0
print(ans)
