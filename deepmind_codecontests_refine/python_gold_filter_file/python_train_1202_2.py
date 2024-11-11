a=input()
num=a.count('L')
num1=a.count('R')
num2=a.count('U')
num3=a.count('D')
lent=len(a)
if (lent%2)==0:
    dif=num-num1
    dif1=num2-num3
    if dif<0:
            dif=-dif
    if dif1<0:
            dif1=-dif1
    if dif>dif1:
        min1=dif1
    else:
        min1=dif
    sub=dif-dif1
    if sub<0:
        sub=-sub
    ans=min1+(sub//2)
    print(ans)
else:
    print("-1")
    
