n = int(input())
w = input().split()
s = []
for i in range(n):
    s.append(int(w[i]))
s.sort()
e = []
k = 1
i = 0
while i + 1< n:
    if s[i] == s[i + 1]:
        k = k + 1
    else:
        e.append(k)
        k = 1
    i = i + 1
if k > 0:
    e.append(k)
ans = 0
m = e[0]
for i in range(1, len(e)):
    ans = ans + min(m, e[i])
    if e[i] > m:
        m = e[i]
print(ans)
    
