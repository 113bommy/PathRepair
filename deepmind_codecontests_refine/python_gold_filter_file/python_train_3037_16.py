import sys,math

def read_int():
    return int(sys.stdin.readline().strip())

def read_int_list():
    return list(map(int,sys.stdin.readline().strip().split()))

def read_string():
    return sys.stdin.readline().strip()

def read_string_list(delim=" "):
    return sys.stdin.readline().strip().split(delim)

def print_list(l, delim=" "):
    print(delim.join(map(str, l)))


###### Author : Samir Vyas #######
###### Write Code Below    #######

n = read_int()
arr = read_int_list()

prefix_sum = [0 for _ in range(n)]

prefix_sum[0] = arr[0]

for i in range(1,n):
	prefix_sum[i] = prefix_sum[i-1] + arr[i]

q = read_int()

for _ in range(q):
	l,r = read_int_list()
	ans = prefix_sum[r-1] - (prefix_sum[l-2] if l > 1 else 0)
	print(int(ans/10))