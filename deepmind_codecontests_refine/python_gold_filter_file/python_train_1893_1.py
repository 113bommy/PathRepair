n = int(input())
distance = [[1000000 for _ in range(n)] for _ in range(n)]

adjMatrix = [[] for _ in range(n)]
for i in range(n):
    adjMatrix[i] = [int(x) for x in input()]
length = int(input())
path = [int(x)-1 for x in input().split()]
for i in range(n):
    for k in range(n):
        if adjMatrix[i][k] == 1:
            distance[i][k] = 1
    



for i in range(n):
    for k in range(n):
        for j in range(n):
            distance[k][j] = min(distance[k][j], distance[k][i] + distance[i][j])
                

answer = []
answer.append(path[0])
leng = 1
for i in range(1,len(path)):
    #print(distance[answer[-1]][path[i]])
    #print(leng)
    if distance[answer[-1]][path[i]] >= leng and answer[-1]!= path[i]:
        leng += 1
    else:
        leng = 2
        answer.append(path[i-1])

answer.append(path[-1])
print(len(answer))

for i in answer:
    print(i+1,end = " ")
