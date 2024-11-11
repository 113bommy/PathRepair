def check(g,h,w,s):
    if (g[0]<0 or g[0]>=h) or (g[1]<0 or g[1]>=w):
        return False
    if s[g[0]][g[1]]==-1:
        return True
    else:
        return False



h,w=map(int,input().split())
c=[int(x)-1 for x in input().split()]
d=[int(x)-1 for x in input().split()]
s=[]
for j in range(h):
    l=[-1 if x=="." else -2 for x in list(input())]
    s.append(l)
s[c[0]][c[1]]=0
u=[c]
i=0
t=0
while t==0:
    for j in u:
        if j==d:
            t=1
            break
        for k in [[j[0]-1,j[1]],[j[0]+1,j[1]],[j[0],j[1]-1],[j[0],j[1]+1]]:
            if check(k,h,w,s):
                s[k[0]][k[1]]=i
                u.append(k)
    i+=1
    v=[]
    for j in u:
        if j==d:
            t=1
            break
        for k1 in range(-2,3):
            for k2 in range(-2,3):
                k=[j[0]+k1,j[1]+k2]
                if check(k,h,w,s):
                    s[k[0]][k[1]]=i
                    v.append(k)
    if v==[]:
        t=1
    u=v
print(s[d[0]][d[1]])