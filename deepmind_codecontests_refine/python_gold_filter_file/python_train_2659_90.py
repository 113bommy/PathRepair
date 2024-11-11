x=input()
y=input()
n,h = x.split()
n=int(n)
h=int(h)
l=y.split()
count=0
for i in range(n):
    if int(l[i])<=h:
        count=count+1
    else :
        count=count+2
print(count)