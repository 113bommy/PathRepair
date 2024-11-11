n = int(input())
mat = list(map(int,input().split()))[::-1]
rmnd = 0
sat = []
for i in mat:
    if rmnd >= i:
        sat.append(rmnd - i + 1)
    else:
        sat.append(0)
        rmnd = i

print(*sat[::-1])
