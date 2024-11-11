n=int(input())
s=list(input())
t=1
for i in range(n-1):
    if ord(s[i])>ord(s[i+1]):
        s.pop(i)
        t-=1
    if t==0:
        break
if t==1:
    for i in range(n-1,0,-1):
        if ord(s[i])>=ord(s[i-1]):
            s.pop(i)
            t-=1
        if t==0:
            break
print("".join(s))

