(n,h),*ab = [list(map(int, s.split())) for s in open(0)]

mxa = max([a for a, b in ab])
bb = sorted([b for a, b in ab if b>mxa],reverse=True)

ans = 0
for b in bb:
    h-=b
    ans += 1
    if h<=0:
        break
if h>0:
    ans += (0--h//mxa)
print(ans)