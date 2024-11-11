s=list(input())
K=int(input())
for i in range(len(s)-1):
    if s[i]!="a":
        a= ord("z")+1 - ord(s[i])
        if K>=a:
            s[i]="a"
            K-=a
if K:
    s[-1]=chr((K+ord(s[-1])-ord("a"))%(ord("z") - ord("a")+1)+ord("a"))
print("".join(s))
