import sys
Input=sys.stdin.readline

a,b = map(int,input().split())
s=list(map(str,input()))
for _ in range(b):
    c , d , e , f=input().split()
    c = int(c)-1
    d = int(d)
    for j in range(c,d):
        if s[j] == e:
            s[j] = f
print(*s,sep="")