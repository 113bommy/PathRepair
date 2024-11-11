n=int(input())
a=[]
b='z'
c="abcdefghijklmnopqrstuvwxyz"
l=0
for i in range(500):
    a.append(i*(i+1)/2)
for i in range(499,0,-1):
    while(n>=a[i]):
        b+=c[l]*(i+1)
        l+=1
        n-=a[i]
print(b)