#!/usr/bin/env python3
import sys

num_queries = 0
visited = []
first = []
last = []

def dfs(start, end):
    if start == end:
        return True
    for i in range(0, num_queries):
        if visited[i] == 0:
            if first[start] > first[i] and first[start] < last[i]:
                visited[i] = 1
                if dfs(i, end):
                    return True;
            elif last[start] > first[i] and last[start] < last[i]:
                visited[i] = 1
                if dfs(i, end):
                    return True;
    return False;

num_lines: sys.stdin.readline()
for line in sys.stdin:
    temp = line.split()
    temp = list(map(int, temp))
    q_type = temp[0]
    if q_type == 1:
        first.append(temp[1])
        last.append(temp[2])
        num_queries += 1
    else:
        visited = [0 for j in range(0, num_queries)]
        visited[temp[1]-1] = 1
        if dfs(temp[1] - 1, temp[2] - 1):
            print("{}".format("YES"))
        else:
            print("{}".format("NO"))
