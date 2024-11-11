'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline
d1=['R','G','B']
d2=['G','B','R']
d3=['B','R','G']
t = int(input())
for _ in range(t):
    n,k=map(int,input().split())
    s=input().strip()
    ans=float('inf')
    temp = s[0:k]
    a = b = c = 0
    p = 0
    q = 1
    r = 2
    for j in temp:
        if j != d1[p]:
            a += 1
        if j != d1[q]:
            b += 1
        if j != d1[r]:
            c += 1
        p += 1
        p %= 3
        q += 1
        q %= 3
        r += 1
        r %= 3
    ans=min(a,b,c)
    # print(a,b,c)
    for i in range(1,n-k+1):
        first=i
        last=i+k-1
        if s[first-1]!=d1[0]:
            a-=1
        if s[first-1]!=d2[0]:
            b-=1
        if s[first-1]!=d3[0]:
            c-=1
        a, b, c = c, a, b
        if s[last]!=d1[(k-1)%3]:
            a+=1
        if s[last]!=d2[(k-1)%3]:
            b+=1
        if s[last]!=d3[(k-1)%3]:
            c+=1
        # print(a,b,c)
        ans=min(ans,a,b,c)
    print(ans)