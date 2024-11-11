h,n = [int(i) for i in input().split()]
dam = [int(i) for i in input().split()]

mi = float("inf")
su = 0
fake = h
flag = False
minu = 0
for v in dam:
    su+=v
    mi = min(mi,su)
    fake += v
    if(fake<=0 and not(flag)):
        flag = True
        minu+=1
    elif(not(flag)):
        minu+=1

if(flag):
    print(minu)
elif(su>=0):
    print(-1)
else:
    full = abs(int((h+mi)/su))
    h+= full*su
    res = full*n

    i = 0
    while h>0:
        h+=dam[i%n]
        res+=1
        i+=1
    print(res)
    
    
