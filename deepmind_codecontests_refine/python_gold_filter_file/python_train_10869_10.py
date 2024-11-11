n=int(input())
x=list(map(int,input().split()))
def func(a,b):
    if a>b:
        return a-b
    else:return b-a
count=func(x[0],x[-1])
a1,b1=0,len(x)-1
for i in range(1,len(x)):
    if func(x[i],x[i-1])<count:
        count=func(x[i],x[i-1])
        a1,b1=i-1,i
    else:continue
print(a1+1,b1+1)
