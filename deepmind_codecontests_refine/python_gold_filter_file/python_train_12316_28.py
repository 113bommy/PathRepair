k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
list=[]
i=1
while i<=d:
    if i%k==0 or i%l==0 or i%m==0 or i%n==0:
        list.append(i)
        i=i+1
    else:
        i=i+1
print(len(list))