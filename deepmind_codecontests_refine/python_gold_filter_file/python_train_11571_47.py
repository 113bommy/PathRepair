n,v=map(int,input().split())
temp=v-1
sum=min(v,n-1)
for i in range(2,n+1):
    # print(sum,temp)
    if temp<v and temp<n-i:
        sum+=(v-temp)*(i)
        temp=v
    temp-=1
print(sum)