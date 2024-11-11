n=int(input())
a=list(input().split())
s=0

for i in a:
    cnt=0
    for j in i:
        if j.isupper():
            cnt+=1
    if s<cnt:
        s=cnt
print(s)