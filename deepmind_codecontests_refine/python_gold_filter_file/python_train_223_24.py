t=int(input())
for _ in range(0,t):
    a,b,n=list(map(int,input().split()))
    if(n%3==0):
        print(a)
    elif(n%3==2):
        print(a^b)
    else:
        print(b)