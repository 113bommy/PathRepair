n=int(input())
c=0
for i in range(n):
    a,b=list(map(int,input().split()))
    a=a+2
    if(a<=b):
        c=c+1 
print(c)