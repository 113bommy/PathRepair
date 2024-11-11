
num_games = int(input())
roster = (1,2)
for game in range(num_games):
    winner = int(input())
    if winner in roster:
        roster = (winner, 6-sum(roster))
    else:
        print( "NO")
        exit()
print("YES")


