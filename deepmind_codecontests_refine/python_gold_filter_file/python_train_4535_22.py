n = int(input())

pos = [int(x) for x in input().split()]
pos.sort()

print(pos[(n-1)//2])
