t=int(input())
for _ in range(t):
    a,b=sorted([int(i) for i in input().split()])
    print((b-a)//10 + ((b-a)%10!=0))
    