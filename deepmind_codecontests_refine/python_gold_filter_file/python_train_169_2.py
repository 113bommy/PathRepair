n=int(input())
s=input()
s=list(s)
l=[]

for i in range(n-1):
    c=0
    for j in range(n-1):
        if s[i]==s[j] and s[i+1]==s[j+1]:
            c=c+1
    l.append(c)
a=l.index(max(l))
for i in range(a,a+2):
    print(s[i],end="")