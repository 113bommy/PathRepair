i=list(map(int,input().split()))
print("win" if sum(i) <= 21 else "bust")