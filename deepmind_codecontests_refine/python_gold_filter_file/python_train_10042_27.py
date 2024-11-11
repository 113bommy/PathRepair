n = int(input())
sum = 0
flag = 0
for i in range(1,n+1):
    sum = sum + i
    if(sum==n):
        flag = 1
if(flag==1):
    print("YES")
elif(flag==0):
    print("NO")