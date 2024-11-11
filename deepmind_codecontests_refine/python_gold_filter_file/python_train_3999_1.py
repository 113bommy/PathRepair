n = int(input())
m = [input() for _ in range(n)]
print(1 if len(m) == 1 else sum(0 if m[i] == m[i+1] else 1 for i in range(len(m)-1))+1)