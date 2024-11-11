A = map(int, input().split())
print("bust" if sum(A)>21 else "win")