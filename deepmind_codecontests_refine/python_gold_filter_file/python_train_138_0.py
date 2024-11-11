'''
http://codeforces.com/contest/242/problem/C
'''
from collections import defaultdict
from heapq import heappush, heappop
INF = int(1e9)

def BFS(x0,y0,x1,y1, graph):
    heap_stack = [[0,x0,y0]]
    visited = set()
    while heap_stack:
        distance, currentX, currentY = heappop(heap_stack)
        if currentX == x1 and currentY == y1: return distance
        for dx, dy in [[1,0],[-1,0],[0,1],[0,-1],[-1,-1],[-1,1],[1,-1],[1,1]]:
            newX, newY = currentX+dx, currentY+dy
            if 1 <= newX <= INF and 1 <= newY <= INF and newY in graph[newX] and (newX, newY) not in visited:
                visited.add((newX, newY))
                heappush(heap_stack, [distance+1, newX, newY])
    return -1

x0,y0,x1,y1 = map(int, input().strip().split(" "))
number_of_allowed_cells = int(input())
graph = defaultdict(set)
for i in range(number_of_allowed_cells):
    row, column1, column2 = map(int, input().strip().split(" "))
    allowed_column = set(range(column1,column2+1))
    graph[row] = graph[row].union(allowed_column)
print(BFS(x0,y0,x1,y1,graph))
                
