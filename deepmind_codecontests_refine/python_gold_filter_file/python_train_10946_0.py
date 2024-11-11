l = list(map(int,input().split()))
week = [0,1,2,0,2,1,0]
whole = min(l[0]//3, l[1]//2,l[2]//2)
l[0] -= 3*(whole)
l[1] -= 2*whole
l[2] -= 2*whole
maxm = 0
for i in range(7):
    x = int(i)
    ite = week[x]
    days = 0
    ls = list(l)
    while True:
        if ls[ite] == 0:
            break
        ls[ite] -= 1
        x+=1
        x%=7
        ite = week[x]
        days+=1
    maxm = max(maxm,days)
print(maxm+7*whole)