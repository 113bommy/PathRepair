n=int(input())
a=list(map(int,input().split()))

s=0
day=0
sm=sum(a)
half=sm/2
for i in a:
    s+=i
    day+=1
    if s>=half:
        print(day)
        break
