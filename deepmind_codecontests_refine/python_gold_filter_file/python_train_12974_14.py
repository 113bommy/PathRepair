n,m=[int(x) for x in input().strip().split()]
l=[int(x) for x in input().strip().split()]
day=0
for k in l:
    day=day+1
    m=m-(86400-k)
    if(m<=0):
        break
print(day)