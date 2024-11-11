t=int(input())
for i in range(t):
    a,b = map(int, input().strip().split(' '))
    s=0
    if a>b:
        c=a-b
    else:
        c=b-a
    d=c//5
    e=c%5
    f=e//2
    g=e%2
    s=d+f+g
    print(s)