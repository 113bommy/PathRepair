rows, cols = tuple(map(int, input().split()))
if cols % 2 == 0:
    result = cols * rows / 2
else:
    result = cols // 2 * rows + rows // 2
print(int(result))
