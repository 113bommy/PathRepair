a=int(input())
b=int(input())
n=(a+b)//2
l=abs(a-n)
r=abs(b-n)
count=0
for x in range(1,l+1):
    count=count+x
for y in range(1,r+1):
    count=count+y
print(count)
