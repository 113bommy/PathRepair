a,b,n=map(float,input().split())
flag=0
for i in range(-1000,1001):
    if a*i**n==b:
        print(i)
        flag=1
        break
if flag==0:
    print("No solution")