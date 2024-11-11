n = int(input())
print("I become the guy." if n==len(set(map(int, input().split()[1:])).union(map(int, input().split()[1:]))) else "Oh, my keyboard!")
