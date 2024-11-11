a=[]
a=map(int,input().split())
b=sum(a)
#print(b%5)
if b%5==0 and b!=0:
    print(int(b/5))
else:
    print(-1)