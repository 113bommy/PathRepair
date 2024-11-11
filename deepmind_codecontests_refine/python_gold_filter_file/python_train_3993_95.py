a,b,c=map(int,input().split())
x=int(a/c)
y=int(b/c)
if not a%c==0:
    x+=1
if not b%c==0:
    y+=1
print(x*y)
    