import sys
input=sys.stdin.readline
s=input().rstrip()
n=len(s)
k=-1
l=[-1]
for c in s:
    while k!=-1 and s[k]!=c:
        k=l[k]
    k+=1
    l+=[k]
q=l[-1]
if l.count(q)<2:
    q=l[q]
print(s[:q] if q>0 else "Just a legend")