#lfrom hxu10 (113540436)
import random
import bisect
import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
 
 
 
n,q = map(int,input().split())
arr = list(map(int,input().split()))
 
freindex = [[] for i in range(n+1)]    
for i in range(n):
    freindex[arr[i]].append(i)
 
res = []
for i in range(q):
    l,r = map(int,input().split())
    l -= 1
    r -= 1
    sublength = r - l + 1
    ans = 1
    s = set()
    for j in range(25):
        randindex = int(random.random()*(sublength))+l
        num = arr[randindex]
        if num in s: continue 
        s.add(num)
        if len(freindex[num])<=(sublength+1)//2: continue
 
        loc1 = bisect.bisect_left(freindex[num],l)
        loc2 = bisect.bisect(freindex[num],r)
        subfre = loc2 - loc1
 
        if subfre>(sublength+1)//2:
            ans = subfre*2-sublength
            break
 
    res += [str(ans)]

print("\n".join(res))
