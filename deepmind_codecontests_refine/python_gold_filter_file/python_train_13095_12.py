n=int(input())
s=input()

c=n

for i in range(0,n-1):
    if s[i]==s[i+1]:
        c-=1

print(c)