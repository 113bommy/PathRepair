def solve(a,b,c,d):
	x = a
	y = c
	min_z = max(c-a+1, c)
	max_z = min(d, c+a-1)
	z = max(min_z, max_z)

	print("{} {} {}".format(x, y, z))

def main():
    t = int(input())
    for _ in range(t):
        a,b,c,d = [int(x) for x in input().split()]
        solve(a,b,c,d)

main()
