N,Q=map(int,input().split())
S=list(input())
S=[0]+S+[N+1]
TD=[list(input().split()) for _ in range(Q)]

def solve(place):
    if place == 0:
        return ('Left')
    elif place == N+1:
        return ('Right')
    for td in TD:
        char,to=td
        if S[place]!=char:continue

        if to=='L':place-=1
        elif to=='R':place+=1

        if place==0:
            return('Left')
        elif place==N+1:
            return('Right')
    return('Not Drop')

l,r=0,N+1
L,R=0,N+1

while abs(r-l)>1:
    m=(l+r)//2
    if solve(m)=='Left':
        L=m
        l,r=m,r
    else:
        l,r=l,m

l,r=0,N+1

while abs(r-l)>1:
    m=(l+r)//2
    if solve(m)=='Right':
        R=m
        l,r=l,m
    else:
        l,r=m,r

print(max(R-L-1,0))
