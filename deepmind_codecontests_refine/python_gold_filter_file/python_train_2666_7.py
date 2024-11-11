n=int(input())
s=input().split()
c=0
mc=None 
for i in s:
    c=0
    for j in i:
        if j>='A' and j<='Z':
            c=c+1 
    if mc==None or mc<c:
        mc=c
print(mc)
        