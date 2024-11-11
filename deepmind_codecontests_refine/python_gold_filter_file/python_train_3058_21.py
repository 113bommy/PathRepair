a,b,n=map(int,input().split())
x=str(a)
flag=0
for i in range(10):
    if int(str(a)+str(i))%b==0:
        x+=str(i)
        flag=1
        break
if flag==0:
    print(-1)
else:    
    for i in range(n-1):
        x+="0"
    print(x)