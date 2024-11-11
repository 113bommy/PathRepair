def main():
	n = int(input())
	print(solver(n))

def quadraticEqPlus(a, b, c):
	return (-b + (b**2 - 4 * a * c)**0.5) / (2 * a)

def solver(n):
	x = int(quadraticEqPlus(0.5, -0.5, 1 - n))
	y = x**2 / 2 - x / 2 + 1
	return int(n - y + 1)

main()

