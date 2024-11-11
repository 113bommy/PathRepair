class House:

	def __init__(self, length, center):
		self.length = length
		self.center = center


def main():
	n, t = map(int, input().split())
	count = 0
	houses = []

	for i in range(0, n):
		x, a = map(int, input().split())
		houses.append(House(a, x))
	houses = sorted(houses, key=lambda house: house.center)

	begin = 0
	prev_end = -10000
	for h in houses:
		begin = h.center - h.length/2
		space = abs(begin - prev_end)
		if space > t:
			count += 2
		elif space == t:
			count += 1
		prev_end = h.center + h.length/2
	print (count)


if __name__ == "__main__":
    main()



#  		 |-----------|        |-----|         
# -4 -3 -2 -1  0  1  2  3  4  5  6  7