n = int(input())
mn = -2000000000
mx = 2000000000
for i in range(n):
    znak, m, ans = map(str, input().split())
    if znak == '>':
        if ans == 'Y':
            mn = max(mn, int(m) + 1)
        else:
            mx = min(mx, int(m))
    if znak == '<':
        if ans == 'Y':
            mx = min(mx, int(m) - 1)
        else:
            mn = max(mn, int(m))
    if znak == '>=':
        if ans == 'Y':
            mn = max(mn, int(m))
        else:
            mx = min(mx, int(m) - 1)
    if znak == '<=':
        if ans == 'Y':
            mx = min(mx, int(m))
        else:
            mn = max(mn, int(m) + 1)
if mx < mn:
    print("Impossible")
else:
    print((mx + mn) // 2)
            
            