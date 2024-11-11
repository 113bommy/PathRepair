a,b,n=map(int,input().split())
flg=0
for i in range(0,10):
    a=str(a)
    if(int(a+str(i))%b==0):
        num=i
        flg=1
        break
if(flg==1):
    a=str(a)
    a+=str(num)
    for i in range(n-1):
        a+="0"
    print(int(a))
else:
    print(-1)
        
    
        
