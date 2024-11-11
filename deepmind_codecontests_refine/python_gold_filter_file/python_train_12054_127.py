N = int(input())

l = [i for i in range(N+1) if i % 3 != 0 and i % 5 != 0]
print(sum(l))