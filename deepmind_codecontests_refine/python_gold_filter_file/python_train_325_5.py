n,x,y=map(int,input().split())
s=input()
s1="1"+"0"*y
s2="1"+"0"*(x-y-1)
ss="0"*(n-x-1)+s2+s1
c=0
for i in range(n-x,n):
    if s[i]!=ss[i]:
        c+=1
print(c)
