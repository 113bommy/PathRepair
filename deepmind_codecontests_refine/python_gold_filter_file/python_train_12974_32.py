input1 = input().split()

days = input1[0]
time = int(input1[1])

total_input = 0
time_left = 0
day = 0
answer = input().split()

while(total_input < int(days)):
    time_left = 86400 - int(answer[total_input])
    time = time - time_left
    day = day + 1
    if(time <= 0):
        break;
    total_input += 1

print(day)
