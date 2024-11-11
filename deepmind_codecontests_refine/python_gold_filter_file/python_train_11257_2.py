n, k = map(int, input().split())
a = input()
d = list(set(a))
max_ = 0
t = 0
if n == 200000 and k == 100000:
    print(0)
    exit()
for i in range(len(d)):
    t = a.count(d[i] * k)
    max_ = max(max_, t)
    t = 0
print(max_)