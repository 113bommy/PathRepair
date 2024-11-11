a,b=map(int,input().split())
for i in range(0,b):
    if a%10==0:
        a=a//10
    else:
        a-=1
print(a)