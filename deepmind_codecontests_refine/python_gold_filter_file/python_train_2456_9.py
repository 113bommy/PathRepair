x,y=map(int,input().split())
list1=list(map(int,input().split()))
k=min(list1)
z=0
for i in list1:
    if (i-k)%y==0:
        z+=((i-k)//y)
    else:
        z=-1
        break
print(z)