goals = int(input())

goal = 0
team = None
win =  None

while goals:
    if goal != 0:
        team = input()
        if team == win:
            goal += 1
        else:
            goal -= 1

    else:
        win = input()
        goal = 1

    goals -= 1

print("\n")
print(win)