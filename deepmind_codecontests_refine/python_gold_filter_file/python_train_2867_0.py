n,k = map(int,input().split())
a,b,c,d = map(int,input().split())
notUse = [a,b,c,d]
if n >= k or n == 4:
    print(-1)
    exit()
f = [a,c]
cntr = 0
for i in range(n-4):
    cntr += 1
    while cntr in notUse:
        cntr+=1
    f.append(cntr)

f+=[d,b]

bk = [c,a]
cntr = 0
for i in range(n-4):
    cntr += 1
    while cntr in notUse:
        cntr+=1
    bk.append(cntr)

bk+=[b,d]

print(" ".join(map(str,f)))
print(" ".join(map(str,bk)))