num = int(input())
data = [int(i) for i in input().split()]
t = max(data)
s = min(data)
moves = moves_t = 0
moves_s = -1
while data[moves_t] != t:
    moves_t += 1
while data[moves_s] != s:
    moves_s -= 1
moves = moves_t + abs(moves_s) - 1

if moves_t - 1 > len(data) + moves_s - 1:
    moves -= 1

print(moves)