n= int(input())
ans=0
for i in range(0,n):
    str= input().split()
    if int(str[1])-int(str[0])>=2:
        ans+=1
print(ans)