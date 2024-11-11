r,c = map(int,input().split())
mat = [[i for i in map(int,input().split())] for _ in range(r)]
c_sum = [0 for _ in range(c+1)]
for i in mat :
    i.append(sum(i))
    for j in range(len(i)) :
        c_sum[j] += i[j]
    
mat.append(c_sum)
for i in mat :
    print(" ".join(list(map(str,i))))
    
    