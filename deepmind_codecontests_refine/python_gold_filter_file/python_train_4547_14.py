n = int(input())
mylist = [int(x) for x in input().split()]
sum = 0
for x in mylist:
    sum+=x
arav = sum/n
if int((arav*10)%10)>4:
    arav = int(arav)+1
else:
    arav = int(arav)
if arav == 5:
    print(0)
else:
    ans = 0
    mylist.sort()
    for x in mylist:
        sum-=x
        sum+=5
        arav = sum/n
        if int((arav*10)%10)>4:
            arav = int(arav)+1
        else:
            arav = int(arav)
        ans+=1
        if arav == 5:
            print(ans)
            break