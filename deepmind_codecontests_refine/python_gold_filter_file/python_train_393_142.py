s = list(map(int, input()))
print(min(len(s)-sum(s), sum(s))*2)