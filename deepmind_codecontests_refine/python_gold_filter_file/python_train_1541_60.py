s = list(map(int, input().split()))
print("win" if(sum(s) <= 21) else "bust")