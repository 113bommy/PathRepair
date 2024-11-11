import sys

#comment these out later
#sys.stdin = open("in.in", "r")
#sys.stdout = open("out.out", "w")

input = sys.stdin.readline

def main():
	t = int(input())
	#t = 1

	for _ in range(t):
		n = int(input())
		ar = list(map(int, input().split()))

		ans = False

		if n%2:
			for i in range(n-1):
				if ar[i] >= ar[i+1]:
					ans = True
					break

			if ans:
				print("YES")
			else:
				print("NO")

		else:
			print("YES")
			continue 


main()