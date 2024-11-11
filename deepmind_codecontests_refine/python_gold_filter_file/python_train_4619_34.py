t=int(input())
x=0
for i in range(t):
    a,b,c=map(int,input().split())
    if(a+b+c>=2):
        x+=1
print(x)