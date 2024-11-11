from sys import stdin, stdout
from collections import deque
sze = 26

s = stdin.readline().strip()
second = []
third = []

position = [-1 for i in range(sze)]
for i in range(len(s)):
    position[ord(s[i]) - ord('a')] = i


i = 0
for k in range(sze):
    if position[k] == -1:
        continue
    
    while (second and ord(second[-1]) - ord('a') <= k):
        third.append(second.pop())    
    
    while i <= position[k]:
        if ord(s[i]) - ord('a') == k:
            third.append(s[i])
        else:
            second.append(s[i])
        
        i += 1

third.extend(second[::-1])
stdout.write(''.join(third))