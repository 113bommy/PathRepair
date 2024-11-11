# import sys
# input=sys.stdin.readline
d=[]
for i in range(3,1000):
    b=set([])
    a=180-360/i
    a=a/(i-2)
    for j in range(1,i-1):
        c=a*j
        if c==int(c):
            b.add(int(c))
    d.append(b)

t=int(input())
for _ in range(t):
    n=int(input())
    for i in range(len(d)):
        if n in d[i]:
            print(i+3)
            break