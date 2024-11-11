n = int(input())
k = (int(input()))
a = [(1<<x)+k*(n-x) for x in range(n+1)]
print(min(a))
