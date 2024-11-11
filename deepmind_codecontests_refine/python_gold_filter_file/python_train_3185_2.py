l,b=map(int,input().split())
i=0
while(l<=b):
    l=3*l
    b=2*b
    i+=1
print(i)