#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

s = input()
s = list(s)
s = [ord(c)-97 for c in s]
f = [0 for i in range(27)]
f[26] = 1
for c in s:
    f[c] += 1
ans = []
stack = []
j = 0
while f[j] == 0:
    j += 1
for c in s:
    stack.append(c)
    f[c] -= 1
    while f[j] == 0:
        j += 1
    while len(stack) > 0 and stack[-1] <= j:
        ans.append(stack.pop())
    #print(c, stack, ans)
while len(stack) > 0:
    ans.append(stack.pop())
print(''.join([chr(i+97) for i in ans]))
