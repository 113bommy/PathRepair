n=int(input())
inp = list(map(int,input().split()))
from collections import Counter
c=Counter(inp)
inp=list(c.keys())
inp.sort()
if(len(inp)>3):
    flag=0
    for i in range(len(inp)-3+1):
        if(inp[i+1]-inp[i]==1 and inp[i+2]-inp[i+1]==1):
            flag=1
            print ('YES')
            break
    if(flag==0):
        print ('NO')
else:
    if(len(inp)==3):
        if(inp[1]-inp[0]==1 and inp[2]-inp[1]==1):
            print ('YES')
        else:
            print ("NO")
    else:
        print ('NO')