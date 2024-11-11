a=int(input())
s=list(map(int,input().split()))
m=0
for n in range(a):
    m+=4*(n)*s[n]
print(m)