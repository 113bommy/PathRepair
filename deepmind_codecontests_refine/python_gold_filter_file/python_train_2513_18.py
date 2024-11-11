n=int(input())
s=input()
r=0
for i in range(n):
    if int(s[i])%2==0:
        r+=i+1
print(r)
