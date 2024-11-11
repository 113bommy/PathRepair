import re, math, decimal, bisect, heapq
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]

# code goes here
n, m = viread()
in_queue = set()
queue = []
for i in input().strip().split():
    if i not in in_queue:
        if len(queue) == m:
            in_queue.remove(queue.pop(0))
        in_queue.add(i)
        queue.append(i)
print(len(queue))
print(" ".join(queue[::-1]))
