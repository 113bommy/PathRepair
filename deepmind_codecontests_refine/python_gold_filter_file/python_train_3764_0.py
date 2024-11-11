a,b,c,d=map(int,input().split())

if(a==(b+c+d)//2):
    num1=b+c-a
    num2=c+d-a
    num3=a-(num1+num2)

elif(b==(a+c+d)//2):
    
    num1=a+c-b
    num2=c+d-b
    num3=b-(num1+num2)

elif(c==(a+b+d)//2):
   
    num1=a+b-c
    num2=b+d-c
    num3=c-(num1+num2)

else:
    num1=a+b-d
    num2=c+b-d
    num3=d-(num1+num2)
print(num1,num2,num3)
