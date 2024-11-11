n=int(input())
x = [int(i) for i in input().split()]
#a=int(input())
#b=int(input())
#c=int(input())
t=0
for i in range(1,n-1):
    a=x[i-1]
    b=x[i]
    c=x[i+1]
    if (b>a and b>c or b<a and b<c):
        t=t+1
print(t)   
    
