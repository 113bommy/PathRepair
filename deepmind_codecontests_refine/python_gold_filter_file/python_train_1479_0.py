from sys import stdin, stdout
from collections import Counter
import math
 
def rsingle_int():
    return int(stdin.readline().rstrip())
 
def rmult_int():
    return [ int(x) for x in stdin.readline().rstrip().split() ]
 
def rmult_str():
    return stdin.readline().rstrip().split()
 
def r_str():
    return stdin.readline().rstrip()
    
def rsingle_char():
    return stdin.read(1)
 
def sortFirst(val):
    return val[0]
 
def main():
    n = rsingle_int()
    cols = [ [] for _ in range(3) ]
    cols[0] = rmult_int()
    cols[1] = rmult_int()
    cols[2] = rmult_int()

    nodes = [ [] for _ in range(n) ]
    edges = []
    for _ in range(n - 1):
        a, b = rmult_int()
        edges.append((a - 1, b - 1))
        nodes[a - 1].append(b - 1)
        nodes[b - 1].append(a - 1)

    possible = True
    for node in nodes:
        if len(node) > 2:
            possible = False
            break
    if not possible:
        print(-1)
    else:
        root = None
        for i, node in enumerate(nodes):
            if len(node) == 1:
                root = i

        if root:
            color_threes = [ [0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 0, 1], [2, 1, 0]]
            min_colors = None
            min_cost = math.inf
            for color_three in color_threes:
                prev_prev = root
                prev = nodes[root][0]
                cost = cols[color_three[0]][prev_prev] + cols[color_three[1]][prev]
                colors = [ None for _ in nodes ]
                colors[prev_prev] = color_three[0] + 1
                colors[prev] = color_three[1] + 1
                i = 2
                while len(nodes[prev]) == 2:
                    curr_col = color_three[i]
                    i = (i + 1) % 3
                    
                    a, b = nodes[prev]
                    current = a
                    if a == prev_prev:
                        current = b 

                    cost += cols[curr_col][current]
                    colors[current] = curr_col + 1
                    prev_prev = prev
                    prev = current
                # print(*colors)
                if cost < min_cost:
                    min_cost = cost
                    min_colors = colors
            print(min_cost)
            print(*min_colors)
        else:
            print(-1)
        
     
 
main()