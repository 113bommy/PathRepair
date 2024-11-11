import math

n, t = map(int, input().split())


buses_arr = []
buses_freq = []

for i in range(n):
    a, b = map(int, input().split())
    buses_arr.append(a)
    buses_freq.append(b)

for i in range(len(buses_arr)):
    if buses_arr[i] < t:
        buses_arr[i] += math.ceil((t - buses_arr[i]) / buses_freq[i]) * buses_freq[i]

print(buses_arr.index(min(buses_arr)) + 1)
