a,m=map(int,input().split())
flag="No"
for i in range(10000):
    if a%m==0:
        flag="Yes"
        break
    a+=(a%m)
print(flag)