import sys
n = int(sys.stdin.readline())
a = list(map(int,sys.stdin.readline().split()))
b =list(map(int,sys.stdin.readline().split()))
kone = a[0]
a.pop(0)
ktwo = b[0]
b.pop(0)
rec =[]
rec.append((a.copy(),b.copy()))
count = 0
repeat = False
while len(a) != 0 and len(b) != 0:
    atemp = a.pop(0)
    btemp = b.pop(0)
    if atemp>btemp:
        a.append(btemp)
        a.append(atemp)
    else:
        b.append(atemp)
        b.append(btemp)
    temp = (a.copy(),b.copy())
    #print(temp,rec,a,b,atemp,btemp)
    if temp in rec:
        repeat = True
        print(-1)
        break
    else:
        rec.append(temp)
        count+=1
if not repeat:
    res = 1 if len(b)==0 else 2
    print(str(count)+" "+str(res))
