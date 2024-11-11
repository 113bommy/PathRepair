n = int(input())
x = range(n)
P =[]
n = 0
for _ in x:P += [[int(i) for i in input().split()]]
P+=[P[0]]
for j in x:n += P[j][0]*P[j+1][1] - P[j][1]*P[j+1][0]
print(n*0.5)