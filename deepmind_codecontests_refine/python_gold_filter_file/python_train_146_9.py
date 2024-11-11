n = int(input())
lis = list(map(int,input().split()))
hun = 0
thun = 0
for i in lis:
    if i == 100:
        hun+=1
    else:
        thun+=1

# print (hun,thun)
if thun == 0 or hun == 0:
    if thun == 0:
        if hun%2 == 0:
            print ('YES')
        else:
            print ('NO')
    else:
        if thun%2 == 0:
            print ('YES')
        else:
            print ('NO')
elif (200*thun+100*hun)%200 == 0:
    print ('YES')
else:
    print ('NO')