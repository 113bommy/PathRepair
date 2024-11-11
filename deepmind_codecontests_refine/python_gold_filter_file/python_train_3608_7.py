
def Slove():
    day=0

    n=int(input())
    a=list(map(int, input().split()))
    sumOfpls=sum(a)
    for i in range(n):
        day+=a[i]
        if(day>=sumOfpls/2):
            return i+1


print(Slove())