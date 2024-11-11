N=int(input())
S=input()

x=0
y=0

for i in S:
    if i=="(":
        x+=1
    else:
        if x<=0:
            y+=1
        else:
            x-=1
print("("*y+S+")"*x)