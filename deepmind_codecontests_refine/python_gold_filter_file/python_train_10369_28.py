import math
x,y,l,r=input().strip().split(' ')
x,y,l,r=(int(x),int(y),int(l),int(r))
list1=[]
a=int(math.log(r,x))
b=int(math.log(r,y))
for i in range(0,a+2):
    for j in range(0,b+2):
        f=x**i+y**j
        if f>=l and f<=r:
            list1.append(f)
if len(list1)==0:
    print(r-l+1)
    exit()
list1.sort()
list2=[0]
list2.append(list1[0]-l)
list2.append(r-list1[-1])
#print("list1 = ",list1)
for i in range(len(list1)-1):
    list2.append(list1[i+1]-list1[i]-1)
print(max(list2))