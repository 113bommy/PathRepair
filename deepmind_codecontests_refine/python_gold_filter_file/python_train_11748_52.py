X, A, B = [int(_) for _ in input().split()]
print(['delicious', 'safe', 'dangerous'][(B-A > 0)+(B-A > X)])
