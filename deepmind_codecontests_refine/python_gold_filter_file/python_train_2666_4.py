input()
l=list(input().split())
m=0;
for i in l:
    a=0
    for j in i:
        if ord(j)<91:
            a+=1;
    m=max(a,m)
print(m)
