n=int(input())
s=input()
ans=1
for i in range(1,n//2+1):
    if s[:i]==s[i:2*i]:
        ans=i
print(n-ans+1)
