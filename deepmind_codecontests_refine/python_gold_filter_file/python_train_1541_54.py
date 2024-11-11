l = list(map(int,input().split()))
print("win" if sum(l) <= 21 else "bust")