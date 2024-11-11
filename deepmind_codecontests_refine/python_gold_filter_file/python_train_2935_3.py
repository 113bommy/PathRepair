n = int(input())
c = ['W', 'B']
for i in range(n):
    tmp = []    
    for j in range(n):
        tmp.append(c[(i + j) % 2])    
    print(''.join(list(map(str, tmp))))