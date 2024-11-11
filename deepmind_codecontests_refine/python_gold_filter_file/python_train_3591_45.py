a,b=map(int,input().split())
x=a-b
y=b-1
if(a==1 and b==1):
    print(a)
elif(x>y):
    print(b+1)
else:
    print(b-1)