#498A
[x1,y1] = list(map(int,input().split()))
[x2,y2] = list(map(int,input().split()))
n = int(input())
s = 0
for i in range(n):
    [a,b,c] = list(map(int,input().split()))
    if (a*x1+b*y1+c)*(a*x2+b*y2+c) < 0:
        s += 1
print(s)