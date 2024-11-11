n = int(input())
P =[]
s = 0
x0,y0 = [int(i) for i in input().split()]
for i in range(n-1):
    x,y = [int(i) for i in input().split()]
    P.append([x-x0,y-y0])
for i in range(n-2):
    s += P[i][0]*P[i+1][1] - P[i][1]*P[i+1][0]
print(abs(s)*0.5)