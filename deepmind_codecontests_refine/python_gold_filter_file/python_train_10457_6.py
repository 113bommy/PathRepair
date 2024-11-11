k, a, b = map(int, input().split())
s, c = input(), 0
if len(s) not in range(k * a, k * b + 1):
    print('No solution')
    exit()
n, m = divmod(len(s), k)
for i in range(k):
    l = n + (i < m)
    print(s[c:c + l])
    c += l