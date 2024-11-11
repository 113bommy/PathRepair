t=int(input())
while(t>0):
    a,b = [int(x) for x in input().split()]
    if((b-a)%10):
        print(1+abs(b-a)//10)
    else:
        print(abs(b-a)//10)
    t-=1