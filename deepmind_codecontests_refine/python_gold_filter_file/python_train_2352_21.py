s = input().split()
n, m, k = int(s[0]), int(s[1]), int(s[2])
m -= 1
s = input().split()
d = n
for i in range(n):
    if i == m: continue
    if s[i] == '0': continue
    if int(s[i]) > k: continue
    if d > abs(m-i):
        d = abs(m-i)
print(10*d)
