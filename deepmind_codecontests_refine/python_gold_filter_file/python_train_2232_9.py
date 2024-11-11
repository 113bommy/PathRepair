def solve(a, boxes):
    waste = 0
    for box in boxes:
        waste += a[int(box) - 1]
        # print (box)
        # print("waste"+str(waste))
    return waste


if __name__ == "__main__":

    a = list(map(int, input().split()))
    boxes = input()
    # print(boxes)
    solved = solve(a, boxes)
    print(solved)
