sum1=sum(map(int,input().split(" ")))
x=0
if  not sum1%5:
    if sum1==0:
        x+=0
    else:
        x+=sum1//5
else:
    x+=(sum1//5) +1

sum2=sum(map(int,input().split(" ")))
if  not sum2%10:
    if sum2==0:
        x+=0
    else:
        x+=sum2//10
else:
    x+=(sum2//10) +1

if x<=int(input()):
    print("YES")
else:
    print("NO")
    