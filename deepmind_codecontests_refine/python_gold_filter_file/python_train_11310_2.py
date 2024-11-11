n, m, k = [int(x) for x in input().split()]
LL=['']*n
AllCount = 0
for i in range(n):
    LL[i] = input()

for i in range(n):
    length = 0
    for j in range(m):
        if LL[i][j]=='.':
            length+=1
        else:
            if length>=k:
                AllCount+=length-k+1
            length=0
    if length>=k:
        AllCount += length - k + 1
for j in range(m):
    length=0
    for i in range(n):
        if LL[i][j]=='.':
            length+=1
        else:
            if length>=k:
                AllCount+=length-k+1
            length=0
    if length >= k:
        AllCount += length - k + 1

if k==1:
    AllCount//=2
print(AllCount)