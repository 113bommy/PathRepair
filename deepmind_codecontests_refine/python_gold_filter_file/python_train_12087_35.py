n = int(input())
a = list(map(int, input().split()))

print("EASY" if sum(a) == 0 else "HARD")
