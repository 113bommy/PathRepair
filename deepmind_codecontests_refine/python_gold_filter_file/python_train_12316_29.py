k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
s=0
for i in range (1,d+1):
    if i%k==0 and k<=d or i%l==0 and l<=d or i%m==0 and m<=d or i%n==0 and n<=d:
        s=s+1
print(s)
