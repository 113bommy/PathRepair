f=[0]*26
n,k=map(int,input().split())
s=input()
l=0
for i in range(n):
    f[ord(s[i])-ord('a')]+=1 
for i in f:
    if i>k:
        l=1
if l==1:
    print('NO')
else:
    print('YES')