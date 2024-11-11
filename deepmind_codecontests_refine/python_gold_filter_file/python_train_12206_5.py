n=int(input())
a=[int(i) for i in input().split()]
d=sum(a)
flag=0
l=[]
for i in range(0,len(a)):
    e=d-a[i]
    mean=e/(n-1)
#     print(mean)
    if(a[i]==mean):
        l.append(i+1)
# print(l)        
if(len(l)>0):
    print(len(l))
    print(*l)
else:
    print(0)