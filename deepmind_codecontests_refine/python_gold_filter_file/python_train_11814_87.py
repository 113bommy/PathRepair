x,y = map(int,input().strip().split())

board_size = x * y
result = 0
if board_size % 2 == 0:
    result = board_size // 2
else:
    result = (board_size - 1) // 2
print(result)