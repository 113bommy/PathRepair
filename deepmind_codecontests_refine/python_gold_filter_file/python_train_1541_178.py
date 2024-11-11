li = list(map(int,input().split()))
print("bust" if sum(li) >= 22 else "win")
