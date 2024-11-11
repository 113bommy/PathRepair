def check_side(s, a, b, c):
	found, partial_sum = False, 0
	for i in range(a, b, c):
		partial_sum += s[i]
		if found:
			if partial_sum % 2 == 1: return True
		if s[i] % 2 == 0:
			found = True
	return False


def solve(l):
	if sum(l) % 2 == 1: return "First"
	if l[0] % 2 == 1 or l[len(l) - 1] % 2 == 1: return "First"
	if check_side(l, len(l) - 1, 1, -1) or check_side(l, 1, len(l) - 1, 1): return "First"
	return "Second"


n = int(input())
a = [int(i) for i in input().split()]
print(solve(a))