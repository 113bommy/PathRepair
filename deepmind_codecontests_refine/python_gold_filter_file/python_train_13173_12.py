s,n = list(map(int,input().split(' ')))
c=0
l1=[]
for i in range(n):
    s=input()
    l = [int(x) for x in str(s)]
    if 0 in l:
        c=c+1
    else:
        l1.append(c)
        c=0
l1.append(c)
l1.sort()
print(l1[len(l1)-1])
        