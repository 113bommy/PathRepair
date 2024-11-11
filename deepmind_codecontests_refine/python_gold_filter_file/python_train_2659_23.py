n,h=map(int,input().split(" "))
x=list(map(int,input().split(" ")))
width=0
for i in x:
    if(i<=h):
        width+=1
    else:
        width+=(2)
print(width)