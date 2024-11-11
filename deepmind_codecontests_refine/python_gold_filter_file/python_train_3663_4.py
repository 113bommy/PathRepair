n=int(input())
l=list(map(int,input().split()))
s=[i for i in l ]
s.sort()
s.reverse()
c=0
for i in range(n):
    c+=s[i]*i+1
print(c)
for i in s:
    print(l.index(i)+1,end=' ')
    l[l.index(i)]=-1