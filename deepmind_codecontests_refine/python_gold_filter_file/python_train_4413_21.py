
n = int(input())
distance = [0] + list(map(int, input().split()))
number_of_stations = list(map(int, input().split()))
first = min(number_of_stations)
second = max(number_of_stations)
path = 0
flow1 = 0
flow2= 0

if number_of_stations[0] == number_of_stations[1]:
    print(path)

else:
    for i in range(first, second):
        flow1 += distance[i]
    for i in range(second, n+1):
        flow2 += distance[i]
    for i in range(first):
        flow2 += distance[i]
    path = min(flow1, flow2)
    print(path)
