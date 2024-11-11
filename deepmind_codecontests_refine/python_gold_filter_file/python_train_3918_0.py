import heapq

N = int(input())
colors = list(map(int,input().strip().split()))

if N%2 == 0:
	colors.append(0)

heapq.heapify(colors)

# while (len(colors) > 2):
# 	a = heapq.heappop(colors)
# 	b = heapq.heappop(colors)
# 	c = heapq.heappop(colors)
# 	panalty += a + b + c
# 	heapq.heappush(colors,a+b+c)

# print(penalty)


# if(len(colors) % 2 == 0):
#     colors.append(0)

ans = 0

while(len(colors) > 2):
    a = heapq.heappop(colors)
    b = heapq.heappop(colors)
    c = heapq.heappop(colors)
    heapq.heappush(colors,a+b+c)
    ans += a+b+c
    
print(ans)
