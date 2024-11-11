s,n=list(map(int,input().split()))
y=[]
y1=[]
sum1=0
for i in range(1,n+1):
    power=0
    de=i
    while(i%2==0):
        power+=1
        i=i//2
    if sum1+2**power<=s:
        sum1+=2**power
        y.append(de)
sum2=0
for i in range(n,0,-1):
    power=0
    de=i
    while(i%2==0):
        power+=1
        i=i//2
    if sum2+2**power<=s:
        sum2+=2**power
        y1.append(de)
if sum1==s:
    print(len(y))
    print(*y)
elif  sum2==s:
    print(len(y1))
    print(*y1)

else:
    print(-1)

    
    