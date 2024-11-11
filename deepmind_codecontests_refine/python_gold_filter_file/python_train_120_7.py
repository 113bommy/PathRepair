t=int(input())
for i in range(t):
    a,b,c=map(int,input().split())
    sum=0
    while(b>0 and c>1):
        c=c-2
        b=b-1
        sum=sum+3
    while(a>0 and b>1):
        a=a-1
        b=b-2
        sum=sum+3
    print(sum)
        
        