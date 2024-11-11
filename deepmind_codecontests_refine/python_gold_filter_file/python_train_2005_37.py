import sys, math
import io, os
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


for t in range(int(input())):
    n=int(input())
    a=input()
    b=input()
    ans=[]
    for i in range(n):
        if a[i]==b[i]:
            continue
        ans.append(i+1)
        ans.append(1)
        ans.append(i+1)
    print(str(len(ans))+' '+' '.join(map(str,ans)))



