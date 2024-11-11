n,m=map(int,input().split())
list1=list(map(int,input().split()))
list2=list(map(int,input().split()))
list1.sort()
list2.sort()
x=list1[-1]
f=0
for i in range(x,list2[0]):
    if(2*list1[0]<=i and i<list2[0]):
        f=1
        print(i)
        break
if(f==0):
    print(-1)