n = int(input())
c = 1
ans = 1
l = []

for i in range(n-1):
    ans += c
    if ans % n != 0:
        l.append(ans % n)
    else:
        l.append(n)    
    c += 1

print(*l)