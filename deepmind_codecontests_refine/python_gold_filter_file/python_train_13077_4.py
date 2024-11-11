#ROUNIAAUDI
num1,num2=map(int,input().split())
factor=1
if num2-num1<10:
    for i in range(num1+1,num2+1):
        factor*=i
    print(factor%10)
else:
    print(0)

