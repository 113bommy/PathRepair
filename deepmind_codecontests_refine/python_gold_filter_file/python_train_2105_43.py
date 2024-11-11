n=int(input())
s=input()
m=0
n=0
for i in s:
    if i=='L':
        m-=1
    if i=='R':
        n+=1
print(n-m+1)    