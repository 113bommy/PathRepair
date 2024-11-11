#!/usr/bin/env python3

import math

l = int(input())

r = math.floor(math.log2(l))

num_vertex = 0
num_edge = 0

num_vertex += r+1

print_list = []
for i in range(r):
    print_list.append([i+1, i+2, 0])
    print_list.append([i+1, i+2, 2**i])
    num_edge += 2


for i in reversed(range(r+1)):
    if l-2**i >= 2**r:
        print_list.append([i+1, r+1, l-2**i])
        l -= 2**i
        num_edge += 1

print(num_vertex, num_edge)
for i in print_list:
    print(*i)
