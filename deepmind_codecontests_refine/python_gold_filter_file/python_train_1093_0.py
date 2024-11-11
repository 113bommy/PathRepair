def score(value,time,wrongAnswer):
    return max(.3*value,(1-time/250.0)*value-(50 * wrongAnswer))

def actualScore():
    times=input().split()
    times=list(map(int,times))
    wrongAnswer=input().split()
    wrongAnswer=list(map(int,wrongAnswer))
    temp=input().split()
    temp=list(map(int,temp))
    total=0
    for problem in range(len(times)):
        total+=score(500*(problem+1),times[problem],wrongAnswer[problem])
    total+=100*int(temp[0])
    total-=50*int(temp[1])
    return int(total)

def maxPair(theList):
    theMax=0
    for index in range(int(len(theList)/2)):
        if theList[index]+theList[len(theList)-1-index]>theMax:
            theMax=theList[index]+theList[len(theList)-1-index]
    return theMax

def cowBox():
    temp=input().split()
    bells=int(temp[0])
    box=int(temp[1])
    temp=input().split()
    sizes=list(map(int,temp))

    if(box>=bells):
        return sizes[len(sizes)-1]
    if(box==bells/2.0):
        return maxPair(sizes)
    else:
        return max(maxPair(sizes[:len(sizes)-(2*box-bells)]),sizes[len(sizes)-1])
print(cowBox())
