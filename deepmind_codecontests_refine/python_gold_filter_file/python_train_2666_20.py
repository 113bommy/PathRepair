n=int(input())
t=list(map(str,input().split()))
m=0
for i in t:
    s=0
    for j in i:
        if j.isupper():
            s+=1
    if s>m:
        m=s
print(m)