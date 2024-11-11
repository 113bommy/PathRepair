n = int(input())
arr = input().split(); arr = [int(x) for x in arr]
inx = [0, n-1, arr.index(1), arr.index(n)]
print(max([abs(inx[0]-inx[2]), abs(inx[1]-inx[2]), abs(inx[0]-inx[3]), abs(inx[1]-inx[3])]))
