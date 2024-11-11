# cook your dish here
n=int(input())
a=list(map(int,input().split()))

sum1=0
for i in a:
    sum1+=i
    
x=sum1//n    
if(sum1%n==0):
    print(n)
else:
    print(n-1)