n=int(input())
#a=list(map(int,input().split()))
m=str(input())
sum=0
for i in range(n):
    if m[i]=='2' or m[i]=='4' or m[i]=='6' or m[i]=='8':
        sum+=i+1
print (sum)