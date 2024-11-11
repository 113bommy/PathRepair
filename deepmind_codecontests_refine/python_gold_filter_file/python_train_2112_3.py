import sys
import heapq
input = sys.stdin.readline

data = []
for i in range(2 * int(input())):
    data.append(input().split())

avalible = []
result = []
try:
    for i in data[::-1]:
        if i[0] == "-":
            heapq.heappush(avalible, int(i[1]))
        else:
            m = heapq.heappop(avalible)
            result.append(m)
    result = result[::-1]
    avalible = []
    p = 0
    for i in data:
        if i[0] == "-":
            m = heapq.heappop(avalible)
            if m != int(i[1]):
                print("NO")
                sys.exit()
        else:
            heapq.heappush(avalible, result[p])
            p += 1
except Exception:
    print("NO")
    sys.exit()

print("YES")
print(*result)