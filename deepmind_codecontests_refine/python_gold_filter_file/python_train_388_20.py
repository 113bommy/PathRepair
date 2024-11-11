import copy

def chess_min_mov(n, positions):
    black_moves = 0
    black_positions = copy.copy(positions)
    for index in range(1, n+1, 2):
        black_moves += abs(index-black_positions.pop(0))
    white_moves = 0
    for index in range(2, n+1, 2):
        white_moves += abs(index-positions.pop(0))
    return min(black_moves,white_moves)

n = int(input())
positions = list(map(int, input().split(' ')))
print(chess_min_mov(n, sorted(positions)))