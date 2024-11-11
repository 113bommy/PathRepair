import math

def solve():
	a, m = map(int, input().split(' '))
	while m % 2 == 0 : m /= 2
	print(['No', 'Yes'][a % m == 0])

def main():
	solve()
	

if __name__ == '__main__':
	main()