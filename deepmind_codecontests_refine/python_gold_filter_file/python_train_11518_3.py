from copy import *
r = [[] for i in range(6)]
r[1] = [[1,5,9,24],[3,7,11,22]]
r[2] = [[2,6,10,23],[4,8,12,21]]
r[3] = [[13,5,17,21],[14,6,18,22]]
r[4] = [[15,7,19,23],[16,8,20,24]]
r[5] = [[14,9,19,4],[16,10,17,3]]
r[0] = [[13,11,20,2],[15,12,18,1]]
arr = [0]+input().split(' ');
def solve(arr, rot):
    for cycle in rot:
        tmp = arr[cycle[0]]
        arr[cycle[0]] = arr[cycle[1]]
        arr[cycle[1]] = arr[cycle[2]]
        arr[cycle[2]] = arr[cycle[3]]
        arr[cycle[3]] = tmp
    arr = arr[1:]
    res = all(all([arr[x] == arr[i] for x in range(i,i+4)]) for i in range(0,24,4))
    return res
solved = False;
for i in range(6):
    if(solve(copy(arr),r[i])):
        print("YES")
        solved = True
        break
if(not solved):
    print("NO")
