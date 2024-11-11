x,y=map(int,input().split())
i=x
c=0
num=list()
while(c==0 and i<=y):
    
    j=i
    while(j):
        num.append(j%10)
        j=j//10
    num2=set(num)
    if(len(num)==len(num2)):c=i
    num.clear()
    num2.clear()
    i=i+1
if(c!=0):
    print(c)
else:
    print("-1")
        
    