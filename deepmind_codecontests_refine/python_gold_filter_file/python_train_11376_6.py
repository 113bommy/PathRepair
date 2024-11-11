n,l = 0,0
arr = []
for _ in range(int(input())):
    n,length = list(map(int,input().split()))
    arr = [0] + list(map(int,input().split())) +[length]
    lArr = [0]
    rArr = [0]
    s = 1
    lasPos = 0
    time = 0
    for i in range(1,n+2):
        time+=(arr[i]-lasPos)/s
        s+=1
        lasPos = arr[i]
        lArr.append(time)
    s = 1
    lasPos = length
    time = 0
    for i in range(n,-1,-1):
        time += abs(arr[i] - lasPos) / s
        s += 1
        lasPos = arr[i]
        rArr.append(time)

    l = 0
    r = length
    # print(lArr,rArr,arr)
    for i in range(40):
        time = (l+r)/2
#         findingWhereIsleft
        lL = 0
        rR = n+2
        while rR-lL!=1:
            mid = (lL + rR)//2

            if time < lArr[mid]:
                rR = mid
            else:
                lL = mid
        leftCanTo = lL
        lL = 0
        rR = n + 2
        while rR - lL != 1:
            mid = (lL + rR) // 2

            if time < rArr[mid]:
                rR = mid
            else:
                lL = mid
        rightCanTo = lL
        # print(leftCanTo,rightCanTo,time, "TIME")
        posL = arr[leftCanTo] + (time - lArr[leftCanTo])*(1+leftCanTo)
        # print((time - lArr[leftCanTo]),'this')
        posR = arr[n-rightCanTo+1] - (time - rArr[rightCanTo])*(1+rightCanTo)
        # print(posL,posR, "CAN GO")
        if posL < posR:
            l = time
        else:
            r = time
    print(l)