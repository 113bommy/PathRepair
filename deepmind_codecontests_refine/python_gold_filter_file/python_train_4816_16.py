import sys
input = sys.stdin.readline
 
t = int(input())
 
for _ in range(t):
    a = int(input())
    s = list(input().rstrip())
    
    maxx = 0
    counter = 0
    
    for char in s:
        if char == '(':
            counter -= 1
        if char == ')':
            counter += 1
        maxx = max(counter, maxx)
        
    print(maxx)