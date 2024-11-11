n=int(input())
s=input()
l=input()
x=0
for i in range(1,n+1):
    if s[-i:]==l[:i]:x=i
print(2*n-x)