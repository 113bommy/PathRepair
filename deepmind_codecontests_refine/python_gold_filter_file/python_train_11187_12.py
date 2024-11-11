n, k = map(int, input().split())
heights = []
total = 0
i = 1
for item in map(int, input().split()):
    heights.append([item, i])
    total += item
    i += 1
heights.sort()
middle = total // n
if total % n != 0:
    middle += 1
most_h = heights[n - 1][0]
min_h = heights[0][0]
up_ind = n - 1
down_ind = 0
level_down = heights[down_ind][0]
level_up = heights[up_ind][0]
i = 0
action_list = []
while i < k:
    if heights[down_ind][0] < middle and heights[up_ind][0] > middle:
        if heights[down_ind][0] < heights[0][0] or down_ind == 0:
            heights[down_ind][0] += 1
            action_list.append([heights[up_ind][1], heights[down_ind][1]])
            if heights[up_ind][0] > heights[n - 1][0] or up_ind == n - 1:
                heights[up_ind][0] -= 1
                if heights[up_ind][0] < heights[up_ind - 1][0]:
                    up_ind -= 1
                elif heights[up_ind][0] == heights[n - 1][0]:
                    up_ind = n - 1
            else:
                up_ind = n - 1
            if heights[down_ind][0] > heights[down_ind + 1][0]:
                down_ind += 1
            elif heights[down_ind][0] == heights[0][0]:
                down_ind = 0
        else:
            down_ind = 0
    elif heights[up_ind][0] - heights[down_ind][0] > 1:
        if heights[up_ind][0] == middle:
            middle -= 1
        elif heights[down_ind][0] == middle:
            middle += 1
    i += 1
print(heights[up_ind][0] - heights[down_ind][0], len(action_list))
for action in action_list:
    print(*action)

