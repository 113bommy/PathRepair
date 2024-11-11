n = int(input())
a = list(map(int,input().split()))
print("EASY" if set(a) == {0}  else "HARD")