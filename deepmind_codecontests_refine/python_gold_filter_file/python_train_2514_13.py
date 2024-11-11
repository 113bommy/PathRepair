n=int(input())
s=input()
l=['0']+input().split()
for i in range(n):
    x=s[i]
    if l[int(x)]>x:
        break
c=''
k=i
while k<n and l[int(s[k])]>=s[k]:
    c+=l[int(s[k])]
    
    k+=1
    
s=s[:i]+c+s[k:]
print(s)
