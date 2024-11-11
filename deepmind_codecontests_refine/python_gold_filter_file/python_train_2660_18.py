from itertools import combinations
a = list(map(int,input().split()))
l = list(combinations(a,3))
t = 0
d = 0
for i in range(len(l)):
    if(l[i][0]+l[i][1]>l[i][2] and l[i][0]+l[i][2]>l[i][1] and l[i][0]<l[i][1]+l[i][2]):
        t+=1
    elif(l[i][0]+l[i][1]>=l[i][2] and l[i][0]+l[i][2]>=l[i][1] and l[i][0]<=l[i][1]+l[i][2]):
        d+=1
if(t>=1):
    print('TRIANGLE')
elif(d>=1):
    print('SEGMENT')
else:
    print('IMPOSSIBLE')
