n=int(input())
s=input()
c=0
for i in range(0,n):
    if int(s[i])%2==0:
        c+=(i+1)
print(c)