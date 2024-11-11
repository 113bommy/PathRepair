a, t_a = map(int, input().split())
b, t_b = map(int, input().split())
h, m = map(int, input().split(':'))

time = h * 60 + m

start = time
end = time + t_a - 1
start_time = 300
end_time = start_time + t_b - 1

intersections = 0

while start_time <= 1439:
    if end >= start_time and end_time >= start:
        intersections += 1

    start_time += b
    end_time = start_time + t_b - 1

print(intersections)
