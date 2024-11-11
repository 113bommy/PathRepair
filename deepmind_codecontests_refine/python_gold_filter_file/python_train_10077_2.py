a,b = map(int,input().split())
l = []

for i in range(b+1):
    if i >= 22 and i%10>=2:
        l.append((i//10)*(i%10))
l.sort()
ans = 0
for i in l:
    if a >= i: ans+=1
print(ans)

