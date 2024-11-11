import math

def solve(text):
	N = len(text)

	pre_sum = [0]
	cur = 0
	for i in text:
		cur += 1 if i == i.lower() else 0
		pre_sum.append(cur)

	post_sum = [0]
	cur = 0;
	for i in reversed(text):
		cur += 1 if i == i.upper() else 0
		post_sum.append(cur)
	post_sum = list(reversed(post_sum))

	return min(x+y for x,y in zip(pre_sum, post_sum))


from sys import stdin

def main():
	n = stdin.readline()
	print(solve(n.strip()))

if __name__ == "__main__": 
    main()