n=int(input())
s=input().split()
x=1
for i in s:
 if(int(i)%2==0):
  x*=2
print(3**n-x)