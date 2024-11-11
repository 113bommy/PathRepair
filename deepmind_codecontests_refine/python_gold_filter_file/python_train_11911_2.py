from collections import defaultdict
import sys
n=int(input())
arr=list(map(int,input().split()))
d=defaultdict(list)
blocklist=[]
for i in range(len(arr)):
    if(len(d[arr[i]])<2):
        d[arr[i]].append(i)
    else:
        if(arr[i] not in blocklist):
            if(d[arr[i]][0]-d[arr[i]][1]==d[arr[i]][-1]-i):
                d[arr[i]].append(i)
            else:
                blocklist.append(arr[i])
num=len(d)-len(blocklist)
print(num)
for i in sorted(d.keys()):
    if(i not in blocklist):
        dif=0
        if(len(d[i])<2):
            print(i,0)
        else:
            dif=d[i][1]-d[i][0]
            print(i,dif)
