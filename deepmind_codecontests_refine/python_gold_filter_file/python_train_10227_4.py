t=int(input())
for i in range(0,t):
    n,k=[int(i) for i in input().split()]
    if(n<k*k):print("NO")
    elif(n%2==0 and k%2==0):print("YES")
    elif(n%2==1 and k%2==1):print("YES")
    else:print("NO")