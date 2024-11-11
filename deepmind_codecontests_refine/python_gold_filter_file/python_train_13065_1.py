s,m = map(int, input().split())
sm=[]
for i in range(s):
    sm.append(list(map(int,input().split())))
c=0
for l in range(s):
    for x in range(0,2*m,2):
        if sm[l][x]==1 or sm[l][x+1]==1:
            c+=1
print(c)

