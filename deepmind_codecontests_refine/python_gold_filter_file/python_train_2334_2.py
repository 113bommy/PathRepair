import sys
k=int(input())
l=[]
for x in range(4):
    l.append(input().strip())
k=2*k
count=0
max_time=0
for x in range(4):
    for y in range(4):
        if l[x][y]=='.':count+=1
        if l[x][y]!='.':
            max_time=max(max_time, int(l[x][y]))

if count==16:
    print("YES")
    sys.exit()

possible=True
time=1
while time<=max_time:
    count=0
    for x in range(4):
        for y in range(4):
            if l[x][y]!='.':
                if int(l[x][y])==time:count+=1
    if count>k:
        possible=False
        break
    time+=1
if possible:
    print("YES")
else:
    print("NO")


