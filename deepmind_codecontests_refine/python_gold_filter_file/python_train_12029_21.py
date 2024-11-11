su=int(input())
a=0
b=0
c=0
amax=su//1234567
bmax=su//123456
for a in range(amax+1):
    if c>0 or su-a*1234567<0:
        break
    for b in range(bmax+1):
        if su-(a*1234567+b*123456)<0:
            break
        if (su-(a*1234567+b*123456))%1234 == 0:
            c+=1
            break
if c>0:
    print('YES')
else:
    print('NO')
