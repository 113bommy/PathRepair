n,r,avg = map(int,input().split())
ab = [0]*n
for i in range(n):
    a, b = map(int,input().split())
    ab[i] = (b, a)
ab.sort()
summ = avg * n
summ1 = 0
res = 0
for i in range(n):
    summ1 += ab[i][1]
for i in range(n):
    dif = summ - summ1
    now = (r - ab[i][1])
    #print(now, dif)
    if dif <= 0: break
    if now >= dif:
        res += dif * ab[i][0]
        summ1 = summ
    else:
        res += now * ab[i][0]
        summ1 = summ1 + now
        
print(res)
    
    