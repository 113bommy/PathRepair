n=int(input())
a=[]
j=k=0
for i in range(n) :
    a.append(input())
x=a[i]
for i in range(n):
    if a[i]==x:
        j+=1
    else :
        y=a[i]
        k+=1
#print("",x)
if k>j:
    print("",y)
else :
    print("",x)