trees = [int(i) for i in input().split()]
if trees[1] == trees[3]:
    t = trees[1] + abs(trees[2] - trees[0])
    print(str(trees[0]) + ' ' + str(t) + ' ' + str(trees[2]) + ' ' + str(t))
elif trees[0] == trees[2]:
    t = trees[0] + abs(trees[3] - trees[1])
    print(str(t) + ' ' + str(trees[1]) + ' ' + str(t) + ' ' + str(trees[3]))
elif abs(trees[0] - trees[2]) == abs(trees[1] - trees[3]):
    print(str(trees[2]) + ' ' + str(trees[1]) + ' ' + str(trees[0]) + ' ' + str(trees[3]))
else:
    print(-1)
