a,b,n=map(int,input().split())
temp=a
num=1
flag=0
flag1=0
for i in range(0,10):
    temp1=(temp*10)+i
    if temp1%b==0:
        flag=1
        temp=temp1
        #print(temp)
        break
        
if i==9 and flag==0:
    flag1=1
else:
    for i in range(1,n):
        num=num*10
    temp=temp*(num)

if flag1==1:
    print("-1")
else:
    print(temp)
