
def getStreckeOne(t) :

    flagPos = 0
    carPos = 0
    carSpeed = 1

    roadCovered = 0

    while t > 0:
        #calculate time to next flag
        if flagPos + 1 <= n :
            timeToNextFlag = (a[flagPos] - carPos) / carSpeed

        else :
            roadCovered += t * carSpeed
            break

        if t > timeToNextFlag :  #you will cross the next flag
            t -= timeToNextFlag
            carPos = a[flagPos]
            roadCovered = carPos

            carSpeed += 1
            flagPos += 1

        elif t == timeToNextFlag :
            roadCovered = a[flagPos]
            break

        else :
            roadCovered += t * carSpeed
            break


    return roadCovered


def getStreckeTwo(t) :

    flagPos = -1
    carPos = l
    carSpeed = 1

    roadCovered = 0

    while t > 0:
        #calculate time to next flag
        if - flagPos <= n :
            timeToNextFlag = (carPos - a[flagPos]) / carSpeed

        else :
            roadCovered += t * carSpeed
            break

        if t > timeToNextFlag :  #you will cross the next flag
            t -= timeToNextFlag
            carPos = a[flagPos]
            roadCovered = l - carPos

            carSpeed += 1
            flagPos -= 1

        elif t == timeToNextFlag :
            roadCovered = l - a[flagPos]
            break

        else :
            roadCovered += t * carSpeed
            break

    return roadCovered




t = int(input())


for _ in range(t) :
    n,l = list(map(int,input().split()))
    a = list(map(int,input().split()))

    A,B = 0,l
    while True :
        AB = (A + B) / 2

        s1,s2 = getStreckeOne(AB),getStreckeTwo(AB)

        if  B - A <= 10 ** -6 :
            break

        elif s1 + s2 > l: #time is to big
            B = AB

        elif s1 + s2 < l : #time is too small
            A = AB

        elif s1 + s2 == l :
            break

    print(AB)


