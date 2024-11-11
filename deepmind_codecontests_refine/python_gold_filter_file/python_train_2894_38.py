N, Q = (int(i) for i in input().split())
ab = [[int(i) for i in input().split()] for i in range(N-1)] 
px = [[int(i) for i in input().split()] for i in range(Q)] 
ab.sort()

weight = [0]*N
for i in range(len(px)):
	weight[px[i][0]-1]+=px[i][1]

for g in range(len(ab)):
	weight[ab[g][1]-1] += weight[ab[g][0]-1]

print(*weight)