n,m = list(map(int,input().split()))
l,h = 1,n
for i in range(m):
    s = input().split()
    v = int(s[-1])
    d = s[2]
    if d == 'left':
        h = min(h,v-1)
    else:
        l = max(l,v+1)
output = h-l+1
if output <= 0:
    print(-1)
else:
    print(output)