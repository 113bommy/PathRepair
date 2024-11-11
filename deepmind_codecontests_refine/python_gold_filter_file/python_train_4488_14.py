n,k=map(int,input().split())
s=input()
p=[0]*k
t='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
b=t[:k]
for i in s:
    if i in b:
        p[ord(i)-65]+=1
print(min(p)*k)
