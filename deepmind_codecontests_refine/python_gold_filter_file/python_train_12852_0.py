n, k = map(int, input().split())
floors = list(sorted(list(map(int, input().split())), reverse = True))
print(sum(2 * x - 2 for x in floors[::k]))