from math import sqrt

coords = [int(i) for i in input().strip().split(' ')]

n = int(input().strip())

taxi_coords = []
for i in range(n):
	taxi_coords.append([int(j) for j in input().strip().split(' ')])

my_min = sqrt((coords[0] - taxi_coords[0][0]) ** 2 + (coords[1] - taxi_coords[0][1]) ** 2) / taxi_coords[0][2]
for taxi in taxi_coords:
	distance = sqrt((coords[0] - taxi[0]) ** 2 + (coords[1] - taxi[1]) ** 2) / taxi[2]
	if distance < my_min:
		my_min = distance

print(my_min)
