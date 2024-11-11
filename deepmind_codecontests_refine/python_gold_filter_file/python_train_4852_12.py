from bisect import bisect_left
n,a=map(int,input().split())
x,y=2,1
z=0
b=[(180*(i-2))/n for i in range(3,n+1)]
def takeClosest(myList, myNumber):
    pos = bisect_left(myList, myNumber)
    if pos == 0:
        return 0
    if pos == len(myList):
        return len(myList)-1
    before = myList[pos - 1]
    after = myList[pos]
    if after - myNumber < myNumber - before:
       return pos
    else:
       return pos-1
z=takeClosest(b,a)+3
print(x,y,z)