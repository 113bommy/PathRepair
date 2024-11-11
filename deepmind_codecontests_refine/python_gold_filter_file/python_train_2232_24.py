import sys
input = sys.stdin.readline

'''

'''

a = [0] + list(map(int, input().split()))
r = input().rstrip()
score = 0
for s in map(int, r):
    score += a[s]

print(score)

