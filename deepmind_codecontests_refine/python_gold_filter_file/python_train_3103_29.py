n = int(input())
ws = list(map(int, input().split()))
print(min([abs(sum(ws[:i+1]) - sum(ws[i+1:])) for i in range(len(ws) - 1)]))
