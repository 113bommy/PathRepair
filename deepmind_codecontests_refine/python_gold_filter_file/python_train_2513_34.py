n=int(input())
s=input()
m=0
for i in range(n):
    if int(s[i])%2==0:
        m=m+i+1
print(m)
