# new_year_garland.py
t = int(input())
while t>0:
    t-=1
    l = list(map(int,input().split()))
    l.sort()
    l[1]-=l[0]
    l[2]-=l[0]
    if l[2]<=l[0]+l[1]+1:
        print('YES')
    else:
        print("NO")