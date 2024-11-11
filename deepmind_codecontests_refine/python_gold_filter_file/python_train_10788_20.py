n = int(input())
u,d = 0,0 
for i in range(n):
    x,y = map(int, input().split())
    if x > 0:
        u +=1
    else:
        d += 1
if u <= 1 or d <= 1:
    print('Yes')
else:
    print('No')