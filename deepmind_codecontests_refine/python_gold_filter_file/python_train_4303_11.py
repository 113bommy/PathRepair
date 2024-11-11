for _ in range(int(input())):
    a,b=map(int,input().split())
    temp=abs(a-b)
    if temp==0:
        print(0,0)
        continue
    temp2=min(a%temp,b%temp,abs(temp-(a%temp)),abs(temp-(b%temp)))
    print(temp,temp2)