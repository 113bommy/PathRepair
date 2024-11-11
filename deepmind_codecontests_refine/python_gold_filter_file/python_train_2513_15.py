n=int(input())
s=input()
sum=0
for i in range(n):
    if(int(s[i])%2==0):
        sum+=i+1
print(sum)