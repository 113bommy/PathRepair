n = int(input())
x = range(n)
P =[]
s = 0
for i in x:P += [[int(i) for i in input().split()]]
P+=[P[0]]
for i in x:s += P[i][0]*P[i+1][1] - P[i][1]*P[i+1][0]
print(s*0.5)