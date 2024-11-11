n,k=map(int,input().split())
s=sorted([[int(i) for i in input().split()] for l in range(n)])
c=0
for x in s:
    c+=x[1]
    if c>=k:
        print(x[0])
        break