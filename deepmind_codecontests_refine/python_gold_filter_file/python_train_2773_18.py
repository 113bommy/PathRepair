minutes = int(input())
hours_of_day = 24
minutes_of_hour = 60
desired_time = input().split()
time_dict = {'hour': desired_time[0], 'minutes': desired_time[1]}
happy_digit = '7'

if happy_digit in time_dict.get('hour') or happy_digit in time_dict.get('minutes'):
    print(0)
else:
    count_tries = 0
    while all([happy_digit not in time_dict.get('hour'), happy_digit not in time_dict.get('minutes')]):
        t = int(time_dict.get('minutes')) - minutes
        if t < 0:
            t = minutes_of_hour - abs(t)
            h = int(time_dict.get('hour')) - 1
            time_dict['hour'] = str(h)
        time_dict['minutes'] = str(t)
        count_tries = count_tries + 1
    print(count_tries)