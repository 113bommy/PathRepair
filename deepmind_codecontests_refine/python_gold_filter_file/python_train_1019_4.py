n=int(input())
s=input()
b=s.count('#')
w=s.count('.')
B=0
ans=w
for i in range(n):
    if s[i]=='#':
        B+=1
    W=n-(i+1)-(b-B)
    ans=min(ans,B+W)
print(ans)
