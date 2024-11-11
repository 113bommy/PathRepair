def get_max_count_dominoes(board_size):
    size_dominoe = 2
    count_dominoes = board_size // size_dominoe
    return count_dominoes

m, n = map(int, input().split())
board_size = m * n

print(get_max_count_dominoes(board_size))