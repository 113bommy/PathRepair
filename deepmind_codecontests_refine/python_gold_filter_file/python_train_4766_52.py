x,y = map(int, input().split())
i = 'Yes' if x * 2 <= y <= x * 4 and y % 2 == 0 else 'No'
print(i)