s,n=map(int,input().split())
l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
l.sort()
ch='YES'
for x in l:
    if x[0]<s:
        s=s+x[1]
    else:
        ch='NO'
        break

print(ch)

