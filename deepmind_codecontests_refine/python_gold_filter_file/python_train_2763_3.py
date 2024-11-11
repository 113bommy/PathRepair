##n = int(input())
##a = list(map(int, input().split()))
##print(" ".join(map(str, res)))

def is_valid(p):
    for i in range(len(pos)):
        if pos[i] == p:
            return True
    return False

n = int(input())
s = list(map(int, input()))

if n <= 1:
    print('NO')
    exit(0)

pos = []
pos.append([3, 1])
pos.append([0, 0])
pos.append([0, 1])
pos.append([0, 2])
pos.append([1, 0])
pos.append([1, 1])
pos.append([1, 2])
pos.append([2, 0])
pos.append([2, 1])
pos.append([2, 2])

cnt = 0
for i in range(10):
    p = pos[i]
    flag = True
    for j in range(1, n):
        mov = [0]*2        
        mov[0] = pos[s[j]][0]-pos[s[j-1]][0]
        mov[1] = pos[s[j]][1]-pos[s[j-1]][1]
        p2 = [0]*2
        p2[0] = p[0]+mov[0]
        p2[1] = p[1]+mov[1]
        if is_valid(p2) == False:
            flag = False
            break
        p = p2
    if flag == True:
        cnt += 1

if cnt > 1:
    print('NO')
else:
    print('YES')
