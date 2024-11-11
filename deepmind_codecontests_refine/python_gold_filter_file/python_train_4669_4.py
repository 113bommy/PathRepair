
n = int(input())
point_list = sorted([[ int(v) for v in input().split() ] for i in range(n) ])
print(point_list[-1][0]+point_list[-1][1])