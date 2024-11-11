import sys

def gravityFlip(cols, ints):
	for idx in range(0, cols-1):
		for col in range(0, cols-1):
			if int(ints[col]) > int(ints[col+1]):
				temp = int(ints[col]) - int(ints[col+1])
				ints[col] = int(ints[col]) - temp
				ints[col+1] = int(ints[col+1]) + temp
	for num in ints:
		print(int(num), end=" ")

def main():
	cols = int(input())
	ints = input().split()
	return gravityFlip(cols, ints)

if __name__ == "__main__":
    main()