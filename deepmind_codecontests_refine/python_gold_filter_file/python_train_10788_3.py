#900A
n = int(input())
pos = 0
neg = 0
for i in range(n):
    [x,y] = list(map(int,input().split()))
    if x > 0:
        pos+=1
    else:
        neg+=1
if pos <= 1 or neg <= 1:
    print('Yes')
else:
    print('No')