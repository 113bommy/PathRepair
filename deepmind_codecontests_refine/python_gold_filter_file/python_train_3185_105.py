l,b=map(int,input().split())
x=0
while l<b+1:
    l=l*3
    b=b*2
    x+=1
print(x)
