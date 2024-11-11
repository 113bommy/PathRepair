n=int(input())
l=1
for i in range(2,int(n**.5)+1):
 if n%i<1:l=i
print(l+n//l-2)