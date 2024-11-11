n = int(input())
a = list(input())
b = list(input())

i1 = 0
i2 = n-1
s = 0

def fun(t1,t2):
    t1.sort()
    t2.sort()
    if t1==t2:
        return True
    elif (t1[0]==t1[1]) and (t2[0]==t2[1]):
        return True
    return False

from collections import Counter
while i1<i2:
    cnt = Counter([a[i1],a[i2],b[i1],b[i2]])
    if len(cnt)==4:
        s+=2
    elif len(cnt)==3:
        if (a[i1]==a[i2]):
            s+=2
        else:
            s+=1
    elif len(cnt)==2:
        if cnt[a[i1]]!=2:
            s+=1
    i1+=1
    i2-=1
if n%2:
    if a[n//2]!=b[n//2]:
        s+=1
print (s)
