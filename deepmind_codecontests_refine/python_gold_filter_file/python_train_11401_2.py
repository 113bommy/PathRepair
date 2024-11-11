n=int(input())
s=input()
c=1
seg=[]
for i in range(1,n):
    if s[i]==s[i-1]:
        c+=1
    else:
        seg.append(c)
        c=1
seg.append(c)
f=0
for i in range(len(seg)):
    if seg[i]>=3:
        f=max(f,2)
if seg[0]==1 and seg[len(seg)-1]==2 or seg[0]==2 and seg[len(seg)-1]==1:
    f=max(1,f)
if seg[0]==seg[len(seg)-1]==2:
    f=max(f,2)

print(min(n,len(seg)+2))