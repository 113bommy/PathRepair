t=int(input())
def print_sum(a,b):
	x=a+b
	return x
for i in range(t):
    a,b=input().split()
    a=int(a)
    b=int(b)
    print(print_sum(a,b))