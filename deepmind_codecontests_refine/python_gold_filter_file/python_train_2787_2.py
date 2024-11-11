import sys
input=sys.stdin.readline
D=int(input())
c=list(map(int,input().split()))
s=[]
for i in range(D):
    sub=list(map(int,input().split()))
    s.append(sub)
t=[]
for i in range(D):
    t.append(int(input()))

h=0
last=[-1]*26

for i in range(D):
    h+=s[i][t[i]-1]
    last[t[i]-1]=i
    for j in range(26):
        h-=c[j]*(i-last[j])

m=int(input())
for _ in range(m):
    d,q=map(int,input().split())
    h+=s[d-1][q-1]-s[d-1][t[d-1]-1]
    o=t[d-1]
    t[d-1]=q

    pre=1
    for i in range(d-2,-1,-1):
        if t[i]==o:
            break
        pre+=1
    post=1
    for j in range(d,D):
        if t[j]==o:
            break
        post+=1
    h-=c[o-1]*pre*post

    pre = 1
    for i in range(d - 2, -1, -1):
        if t[i] == q:
            break
        pre += 1
    post = 1
    for j in range(d, D):
        if t[j] == q:
            break
        post += 1
    h += c[q - 1] * pre * post

    print(h)


