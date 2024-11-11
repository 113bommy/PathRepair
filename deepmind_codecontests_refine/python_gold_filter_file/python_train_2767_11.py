n,x=int(input()),int(input())
n=n%6
x=x-1;
for i in range(n,0,-1):
    if i%2==0:
        if x==1:
            x=0
        elif x==0:
            x=1
    else:
        if x==-1:
            x=0
        elif x==0:
            x=-1 
print(x+1)
