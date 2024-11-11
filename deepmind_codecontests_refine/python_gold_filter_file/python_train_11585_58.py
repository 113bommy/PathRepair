t=int(input())
while(t):
    t=t-1
    a,b=map(int,input().split())
    print((abs(a-b)+9)//10)