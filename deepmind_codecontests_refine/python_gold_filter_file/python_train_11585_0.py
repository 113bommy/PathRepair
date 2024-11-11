t=int(input())
while t:
    t-=1
    a,b=map(int,input().split())
    s=abs((a-b))//10
    if (a-b)%10!=0:
        s+=1
    print(s)