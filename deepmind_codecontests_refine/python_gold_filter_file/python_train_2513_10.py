n=int(input())
a=input()
sum=0
for i in range(n):
    if int(a[i])%2==0:
        sum=sum+i+1
print(sum)