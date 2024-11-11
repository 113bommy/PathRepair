h, w = map(int, input().split())
A = [[int(i) for i in input().split()] for i in range(h)]
B = []
count = 0

for i in range(h):
    for j in range(w-1):
        if A[i][j] % 2 == 1:
            count += 1
            A[i][j+1] += 1
            B.append([i+1, j+1, i+1, j+2])
            
for i in range(h-1):
    if A[i][-1] % 2 == 1:
        count += 1
        A[i+1][-1] += 1
        B.append([i+1, w, i+2, w])
        
print(count)
for b in B:
    print(b[0], b[1], b[2], b[3])