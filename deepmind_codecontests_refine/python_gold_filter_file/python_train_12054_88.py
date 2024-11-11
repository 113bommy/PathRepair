n = int(input())
print(sum(i for i in range(n+1) if i % 3 and i % 5))