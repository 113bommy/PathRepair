# code by RAJ BHAVSAR
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
def get_int(): return int(sys.stdin.readline().strip())
def get_print_int(x): sys.stdout.write(str(x))
def get_print(x): sys.stdout.write(str(x))

def solve():
	for _ in range(get_int()):
		n = get_int()
		get_print(' '.join(map(str,[1]*n)))
		get_print('\n')

solve()