read = lambda: map(int, input().split())
n, m = read()
a = set(read())
t = []
for i in range(1, m + 1):
    if m < i: break
    if i not in a:
        t.append(i)
        m -= i
print(len(t))
print(*t)
    
